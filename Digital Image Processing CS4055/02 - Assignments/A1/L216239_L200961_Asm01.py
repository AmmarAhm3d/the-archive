"""
Tkinter Image Processing Assignment (Side-by-Side Layout)
- Supports:
  1. Stretching and Shrinking:
     (a) Mapping Equations (linear & piecewise)
     (b) Histogram based
  2. Specified Histogram algorithm (using two images)

Features:
- GUI built with Tkinter.
- Shows Original, Processed, and Specified images side by side.
- Each image has its histogram displayed directly below it (no tabs, no buttons).
- Adds a log text box for displaying intermediate mapping tables (Q2).

Group:
 Ammar Ahmed (L200961)
 Ahmad Naeem (L216239)
"""

import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from io import BytesIO

# ------------------------- Utility functions -------------------------

def pil_to_np(img_pil):
    arr = np.array(img_pil)
    if arr.ndim == 3 and arr.shape[2] == 4:
        arr = arr[:, :, :3]
    return arr.astype(np.uint8)

def np_to_pil(arr):
    if arr.dtype != np.uint8:
        arr = np.clip(arr, 0, 255).astype(np.uint8)
    return Image.fromarray(arr)

def to_grayscale(arr):
    if arr.ndim == 2:
        return arr
    r, g, b = arr[..., 0], arr[..., 1], arr[..., 2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b
    return np.clip(gray, 0, 255).astype(np.uint8)

def compute_histogram(gray):
    h = np.zeros(256, dtype=np.int64)
    flat = gray.flatten()
    for v in flat:
        h[int(v)] += 1
    cdf = np.cumsum(h)
    return h, cdf

# Function to plot histogram and return PIL image
def plot_histogram(gray, title):
    h, _ = compute_histogram(gray)
    fig, ax = plt.subplots(figsize=(3, 2))
    ax.bar(range(256), h, color='blue')
    ax.set_xlim([0, 255])
    ax.set_title(title)
    buf = BytesIO()
    plt.tight_layout()
    fig.savefig(buf, format='png')
    plt.close(fig)
    buf.seek(0)
    return Image.open(buf)

# ------------------------- Part 1a: Mapping Equations -------------------------

def linear_mapping(gray, in_min, in_max, out_min, out_max):
    if in_max == in_min:
        m = 1.0
    else:
        m = (out_max - out_min) / (in_max - in_min)
    b = out_min - m * in_min
    mapped = m * gray.astype(np.float32) + b
    return np.clip(mapped, 0, 255).astype(np.uint8)

def piecewise_linear_mapping(gray, pieces):
    out = gray.astype(np.float32).copy()
    for (is_, ie, os_, oe) in pieces:
        m = (oe - os_) / (ie - is_) if ie != is_ else 1.0
        b = os_ - m * is_
        mask = (gray >= is_) & (gray <= ie)
        out[mask] = m * gray[mask].astype(np.float32) + b
    return np.clip(out, 0, 255).astype(np.uint8)

# ------------------------- Part 1b: Histogram-based -------------------------

def histogram_stretch(gray):
    vmin = int(gray.min())
    vmax = int(gray.max())
    return linear_mapping(gray, vmin, vmax, 0, 255)

def histogram_shrink(gray, out_min=75, out_max=175):
    vmin = int(gray.min())
    vmax = int(gray.max())
    return linear_mapping(gray, vmin, vmax, out_min, out_max)

# ------------------------- Part 2: Histogram Specification -------------------------

def histogram_specification(source_gray, target_gray, log_callback=None):
    # Step 1: Source mapping
    hS, cdfS = compute_histogram(source_gray)
    totalS = cdfS[-1]
    map1 = np.round(cdfS / totalS * 255).astype(np.uint8)
    if log_callback:
        log_callback("Mapping Table 1 (Source -> Equalized):\n" + str(dict(enumerate(map1))) + "\n")

    # Step 2: Target mapping
    hT, cdfT = compute_histogram(target_gray)
    totalT = cdfT[-1]
    map2 = np.round(cdfT / totalT * 255).astype(np.uint8)
    if log_callback:
        log_callback("Mapping Table 2 (Target -> Equalized):\n" + str(dict(enumerate(map2))) + "\n")

    # Step 3: Invert mapping of target
    inv_map2 = np.zeros(256, dtype=np.uint8)
    for y in range(256):
        candidates = np.where(map2 >= y)[0]
        inv_map2[y] = candidates[0] if candidates.size > 0 else 255

    # Step 4: Final LUT
    final_lut = np.zeros(256, dtype=np.uint8)
    for g in range(256):
        eq = map1[g]
        final_lut[g] = inv_map2[eq]
    if log_callback:
        log_callback("Final LUT (Original -> Specified):\n" + str(dict(enumerate(final_lut))) + "\n")

    # Step 5: Apply LUT
    flat = source_gray.flatten()
    mapped_flat = final_lut[flat]
    return mapped_flat.reshape(source_gray.shape)

# ------------------------- GUI Application -------------------------

class ImageProcessorGUI:
    def __init__(self, master):
        self.master = master
        master.title('Image Processing Assignment - Side by Side')

        self.orig_np = None
        self.proc_np = None
        self.spec_np = None

        control_frame = tk.Frame(master)
        control_frame.pack(side=tk.TOP, fill=tk.X)
        display_frame = tk.Frame(master)
        display_frame.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

        tk.Button(control_frame, text='Load Image', command=self.load_image).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Load Specified Image (Q2)', command=self.load_specified_image).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Linear Mapping (1a)', command=self.apply_linear_mapping).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Piecewise Mapping (1a)', command=self.apply_piecewise_mapping).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Histogram Stretch (1b)', command=self.apply_histogram_stretch).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Histogram Shrink (1b)', command=self.apply_histogram_shrink).pack(side=tk.LEFT)
        tk.Button(control_frame, text='Histogram Specification (Q2)', command=self.apply_histogram_specification).pack(side=tk.LEFT)

        # Panels for Original, Processed, Specified
        self.panels = {}
        for label in ["Original", "Processed", "Specified"]:
            frame = tk.Frame(display_frame, bd=2, relief=tk.GROOVE)
            frame.pack(side=tk.LEFT, padx=5, pady=5)
            tk.Label(frame, text=label, font=("Arial", 12, "bold")).pack()
            img_label = tk.Label(frame)
            img_label.pack()
            hist_label = tk.Label(frame)
            hist_label.pack()
            self.panels[label] = (img_label, hist_label)

        # Log window for mapping tables
        self.log_text = tk.Text(master, height=10)
        self.log_text.pack(side=tk.BOTTOM, fill=tk.X)

    def log(self, text):
        self.log_text.insert(tk.END, text + "\n")
        self.log_text.see(tk.END)

    def update_panel(self, label, img_np):
        if img_np is None:
            return
        img = np_to_pil(img_np).resize((250, 250))
        hist = plot_histogram(img_np, "Histogram").resize((250, 150))
        img_tk = ImageTk.PhotoImage(img)
        hist_tk = ImageTk.PhotoImage(hist)
        img_label, hist_label = self.panels[label]
        img_label.configure(image=img_tk)
        img_label.image = img_tk
        hist_label.configure(image=hist_tk)
        hist_label.image = hist_tk

    def update_display(self):
        self.update_panel("Original", self.orig_np)
        self.update_panel("Processed", self.proc_np)
        self.update_panel("Specified", self.spec_np)

    def load_image(self):
        path = filedialog.askopenfilename(filetypes=[('Image files', '*.jpg *.jpeg *.png')])
        if not path:
            return
        pil = Image.open(path).convert('RGB')
        self.orig_np = to_grayscale(pil_to_np(pil))
        self.proc_np = self.orig_np.copy()
        self.update_display()

    def load_specified_image(self):
        path = filedialog.askopenfilename(filetypes=[('Image files', '*.jpg *.jpeg *.png')])
        if not path:
            return
        pil = Image.open(path).convert('RGB')
        self.spec_np = to_grayscale(pil_to_np(pil))
        self.update_display()

    def apply_linear_mapping(self):
        if self.orig_np is None:
            return
        self.proc_np = linear_mapping(self.orig_np, 50, 200, 0, 255)
        self.update_display()

    def apply_piecewise_mapping(self):
        if self.orig_np is None:
            return
        pieces = [(0, 100, 0, 150), (100, 255, 150, 255)]
        self.proc_np = piecewise_linear_mapping(self.orig_np, pieces)
        self.update_display()

    def apply_histogram_stretch(self):
        if self.orig_np is None:
            return
        self.proc_np = histogram_stretch(self.orig_np)
        self.update_display()

    def apply_histogram_shrink(self):
        if self.orig_np is None:
            return
        self.proc_np = histogram_shrink(self.orig_np)
        self.update_display()

    def apply_histogram_specification(self):
        if self.orig_np is None or self.spec_np is None:
            return
        self.proc_np = histogram_specification(self.orig_np, self.spec_np, log_callback=self.log)
        self.update_display()

if __name__ == '__main__':
    root = tk.Tk()
    app = ImageProcessorGUI(root)
    root.mainloop()