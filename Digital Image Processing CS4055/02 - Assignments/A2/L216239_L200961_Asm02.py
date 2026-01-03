"""Adaptive contrast enhancement toolkit with GUI.

This script implements multiple ACE variants for grayscale images along with a
color contrast enhancement workflow. All
operations are exposed through a simple Tkinter GUI so users can load a low
contrast image, experiment with the filters, and visualise the results.

Dependencies:
        - numpy
        - opencv-python (cv2)
        - Pillow (PIL)
These need to be installed in the current Python environment.

Group:
 Ammar Ahmed (L200961)
 Ahmad Naeem (L216239)

"""

from __future__ import annotations

import math # instead we use np-math
import tkinter as tk
from dataclasses import dataclass
from typing import Any
from tkinter import filedialog, messagebox

import cv2 # to get hls, hist, blur(mean filt) and merge(stacks channels back)
import numpy as np # np.max np.min np.power np.clip np.sqrt np.square np.cumsum np.zeros np.ndarray np.mean
from PIL import Image, ImageTk


_resampling_module = getattr(Image, "Resampling", Image) # Pillow>=10
RESAMPLE_LANCZOS: Any = getattr(_resampling_module, "LANCZOS", 1) # resampling filter to display images


# --- Image processing helpers -------------------------------------------------


def _ensure_odd(window_size: int) -> int:
    """Force kernel size to be odd and at least 3."""

    window_size = max(3, int(window_size))
    if window_size % 2 == 0:
        window_size += 1
    return window_size


def _local_mean(image: np.ndarray, window_size: int) -> np.ndarray:
    """Compute local mean using a square window."""

    window_size = _ensure_odd(window_size)
    return cv2.blur(image, (window_size, window_size))


def _local_std(image: np.ndarray, window_size: int) -> np.ndarray:
    """Compute local standard deviation in a square window."""

    window_size = _ensure_odd(window_size)
    mean = _local_mean(image, window_size)
    mean_sq = cv2.blur(np.square(image), (window_size, window_size))
    variance = np.maximum(mean_sq - np.square(mean), 0.0)
    std = np.sqrt(variance)
    return np.maximum(std, 1e-3)  # guard against division by zero


def ace_filter(
    image: np.ndarray,
    window_size: int = 9,
    k1: float = 0.8,
    k2: float = 0.2,
) -> np.ndarray:
    """Classic ACE filter using global mean and local statistics."""

    float_image = image.astype(np.float32)
    global_mean = float_image.mean()
    local_mean = _local_mean(float_image, window_size)
    local_std = _local_std(float_image, window_size)

    enhanced = (
        k1 * (global_mean / local_std) * (float_image - local_mean) + k2 * local_mean
    )
    return np.clip(enhanced, 0, 255).astype(np.uint8)


def ace2_filter(
    image: np.ndarray,
    window_size: int = 9,
    k1: float = 0.8,
    k2: float = 0.2,
) -> np.ndarray:
    """Simplified ACE-2 filter using local mean only."""

    float_image = image.astype(np.float32)
    local_mean = _local_mean(float_image, window_size)
    enhanced = k1 * (float_image - local_mean) + k2 * local_mean
    return np.clip(enhanced, 0, 255).astype(np.uint8)


def log_ace2_filter(
    image: np.ndarray,
    window_size: int = 9,
    k1: float = 0.8,
    k2: float = 0.2,
    max_value: float = 255.0,
) -> np.ndarray:
    """Logarithmic ACE-2 variant operating on the complemented, normalised data."""

    epsilon = 1e-6
    float_image = image.astype(np.float32)
    local_mean = _local_mean(float_image, window_size)

    norm_image = 1.0 - (float_image / max_value)
    norm_mean = 1.0 - (local_mean / max_value)

    norm_image = np.clip(norm_image, epsilon, 1.0)
    norm_mean = np.clip(norm_mean, epsilon, 1.0)

    enhanced = k1 * (np.log(norm_image) - np.log(norm_mean)) + k2 * norm_mean
    enhanced = (enhanced - enhanced.min()) / (enhanced.max() - enhanced.min() + epsilon)
    return np.clip(enhanced * max_value, 0, 255).astype(np.uint8)


def exp_ace2_filter(
    image: np.ndarray,
    window_size: int = 9,
    k1: float = 0.8,
    k2: float = 0.2,
    max_value: float = 255.0,
) -> np.ndarray:
    """Exponential ACE filter using the provided formulation."""

    epsilon = 1e-6
    float_image = image.astype(np.float32)
    local_mean = _local_mean(float_image, window_size)

    normalised = np.clip(float_image / max_value, epsilon, 1.0)
    ratio = np.clip(local_mean / np.clip(float_image, epsilon, None), epsilon, None)

    enhanced = max_value * np.power(normalised, k1) + np.power(ratio, k2)
    return np.clip(enhanced, 0, 255).astype(np.uint8)


def color_contrast_enhancement(image_bgr: np.ndarray) -> np.ndarray:
    """Apply the HSL-based color contrast enhancement pipeline."""

    hls_image = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2HLS)
    h, l, s = cv2.split(hls_image)

    # Histogram equalisation on saturation
    s_eq = cv2.equalizeHist(s)

    # Histogram stretch on lightness
    l_min, l_max = np.min(l), np.max(l)
    if l_max - l_min < 1e-3:
        l_stretched = l.copy()
    else:
        l_stretched = (l - l_min) * (255.0 / (l_max - l_min))
        l_stretched = np.clip(l_stretched, 0, 255).astype(np.uint8)

    merged = cv2.merge((h, l_stretched, s_eq))
    enhanced_bgr = cv2.cvtColor(merged, cv2.COLOR_HLS2BGR)
    return enhanced_bgr


# --- GUI ----------------------------------------------------------------------


@dataclass
class FilterConfig:
    window_size: int = 9
    k1: float = 0.8
    k2: float = 0.2


class ACEGUI:
    """Tkinter based interface to load images and apply the ACE filters."""

    def __init__(self, root: tk.Tk) -> None:
        self.root = root
        self.root.title("Adaptive Contrast Enhancement Toolkit")
        self.config = FilterConfig()

        self.original_bgr: np.ndarray | None = None
        self.original_gray: np.ndarray | None = None
        self.processed_image: np.ndarray | None = None

        self._build_controls()

    # --- UI construction -----------------------------------------------------

    def _build_controls(self) -> None:
        control_frame = tk.Frame(self.root, padx=10, pady=10)
        control_frame.pack(side=tk.TOP, fill=tk.X)

        tk.Button(control_frame, text="Load Image", command=self.load_image).grid(
            row=0, column=0, padx=5, pady=5
        )

        tk.Label(control_frame, text="Window (odd)").grid(row=0, column=1, padx=5)
        self.window_var = tk.IntVar(value=self.config.window_size)
        tk.Spinbox(
            control_frame,
            from_=3,
            to=99,
            increment=2,
            textvariable=self.window_var,
            width=5,
        ).grid(row=0, column=2, padx=5)

        tk.Label(control_frame, text="k1").grid(row=0, column=3, padx=5)
        self.k1_var = tk.DoubleVar(value=self.config.k1)
        tk.Spinbox(
            control_frame,
            from_=0.0,
            to=5.0,
            increment=0.1,
            textvariable=self.k1_var,
            width=5,
        ).grid(row=0, column=4, padx=5)

        tk.Label(control_frame, text="k2").grid(row=0, column=5, padx=5)
        self.k2_var = tk.DoubleVar(value=self.config.k2)
        tk.Spinbox(
            control_frame,
            from_=0.0,
            to=5.0,
            increment=0.1,
            textvariable=self.k2_var,
            width=5,
        ).grid(row=0, column=6, padx=5)

        button_frame = tk.Frame(self.root, padx=10, pady=10)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        tk.Button(button_frame, text="ACE", command=self.apply_ace).pack(
            side=tk.LEFT, padx=5
        )
        tk.Button(button_frame, text="ACE-2", command=self.apply_ace2).pack(
            side=tk.LEFT, padx=5
        )
        tk.Button(button_frame, text="Log-ACE2", command=self.apply_log_ace2).pack(
            side=tk.LEFT, padx=5
        )
        tk.Button(button_frame, text="Exp-ACE2", command=self.apply_exp_ace2).pack(
            side=tk.LEFT, padx=5
        )
        tk.Button(
            button_frame,
            text="Color Contrast Enhancement",
            command=self.apply_color_enhancement,
        ).pack(side=tk.LEFT, padx=5)

        image_frame = tk.Frame(self.root, padx=10, pady=10)
        image_frame.pack(fill=tk.BOTH, expand=True)

        self.original_panel = tk.Label(
            image_frame, text="Original image will appear here"
        )
        self.original_panel.pack(side=tk.LEFT, padx=10)

        self.processed_panel = tk.Label(
            image_frame, text="Processed image will appear here"
        )
        self.processed_panel.pack(side=tk.LEFT, padx=10)

    # --- Utility methods -----------------------------------------------------

    def load_image(self) -> None:
        filetypes = [
            ("Image files", "*.png *.jpg *.jpeg *.bmp *.tif *.tiff"),
            ("All files", "*.*"),
        ]
        file_path = filedialog.askopenfilename(
            title="Select an image", filetypes=filetypes
        )
        if not file_path:
            return

        image_bgr = cv2.imread(file_path, cv2.IMREAD_COLOR)
        if image_bgr is None:
            messagebox.showerror("Load error", "Unable to read the selected image.")
            return

        self.original_bgr = image_bgr
        self.original_gray = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2GRAY)
        self.processed_image = None

        self._display_image(self.original_panel, self.original_bgr)
        self.processed_panel.config(text="Apply a filter to see the result")

    def _get_params(self) -> FilterConfig:
        return FilterConfig(
            window_size=int(self.window_var.get()),
            k1=float(self.k1_var.get()),
            k2=float(self.k2_var.get()),
        )

    def _require_image(self) -> bool:
        if self.original_bgr is None:
            messagebox.showwarning("No image", "Please load an image first.")
            return False
        return True

    def _display_image(self, panel: tk.Label, image: np.ndarray) -> None:
        if image.ndim == 2:
            image_rgb = cv2.cvtColor(image, cv2.COLOR_GRAY2RGB)
        else:
            image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        pil_image = Image.fromarray(image_rgb)
        max_dim = 400
        pil_image.thumbnail((max_dim, max_dim), RESAMPLE_LANCZOS)

        photo = ImageTk.PhotoImage(pil_image)
        panel.configure(image=photo)
        setattr(panel, "_photo_image", photo)  # keep reference alive

    def _update_processed(self, image: np.ndarray) -> None:
        self.processed_image = image
        self._display_image(self.processed_panel, image)

    # --- Filter callbacks ----------------------------------------------------

    def apply_ace(self) -> None:
        if not self._require_image():
            return

        params = self._get_params()
        assert self.original_gray is not None
        result = ace_filter(
            self.original_gray, params.window_size, params.k1, params.k2
        )
        self._update_processed(result)

    def apply_ace2(self) -> None:
        if not self._require_image():
            return

        params = self._get_params()
        assert self.original_gray is not None
        result = ace2_filter(
            self.original_gray, params.window_size, params.k1, params.k2
        )
        self._update_processed(result)

    def apply_log_ace2(self) -> None:
        if not self._require_image():
            return

        params = self._get_params()
        assert self.original_gray is not None
        result = log_ace2_filter(
            self.original_gray,
            params.window_size,
            params.k1,
            params.k2,
        )
        self._update_processed(result)

    def apply_exp_ace2(self) -> None:
        if not self._require_image():
            return

        params = self._get_params()
        assert self.original_gray is not None
        result = exp_ace2_filter(
            self.original_gray,
            params.window_size,
            params.k1,
            params.k2,
        )
        self._update_processed(result)

    def apply_color_enhancement(self) -> None:
        if not self._require_image():
            return

        assert self.original_bgr is not None
        result = color_contrast_enhancement(self.original_bgr)
        self._update_processed(result)


def main() -> None:
    root = tk.Tk()
    app = ACEGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
