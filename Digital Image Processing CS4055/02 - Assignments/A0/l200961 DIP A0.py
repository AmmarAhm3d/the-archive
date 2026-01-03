"""
Name: Ammar Ahmed Roll: 20L-0961

Image Channel Separation and Spatial Reduction GUI Application.
Loads an image, allows viewing original and separated channels (R, G, B),
and reduces the image to specified dimensions centered in original canvas size.

Uses Tkinter for GUI, OpenCV for image loading only; all processing is manual.

To run, ensure you have Python with Tkinter and OpenCV installed.

    pip install opencv-python tkinter
"""

import cv2
import os
import tkinter as tk
from tkinter import filedialog, messagebox
from typing import Optional, Tuple

# Only using cv2 to read image into matrix; all processing manual.


class ImageProcessor:
    """Handles image loading, channel separation, and spatial reduction."""

    def __init__(self):
        """Initialize the ImageProcessor with no image loaded."""
        self.original_bgr = None  # BGR order from OpenCV
        self.path = None

    def load_image(self, path: str) -> None:
        """Load an image from a file path.

        Args:
            path (str): The file path to the image.

        Raises:
            FileNotFoundError: If the file does not exist.
            ValueError: If the image cannot be loaded.
            ValueError: If the image is unsupported or corrupt.

        Returns:
            None
        """
        if not os.path.isfile(path):
            raise FileNotFoundError("File does not exist")
        img = cv2.imread(
            path, cv2.IMREAD_COLOR
        )  # BGR format needed to read colors correctly
        if img is None:
            raise ValueError("Failed to load image. Unsupported or corrupt.")
        self.original_bgr = img
        self.path = path

    def get_canvas_size(self) -> Tuple[int, int]:
        """Get the size of the original image canvas.

        Returns:
            Tuple[int, int]: The width and height of the canvas.
        """
        if self.original_bgr is None:
            return (0, 0)
        h, w = self.original_bgr.shape[:2]
        return (w, h)

    def channel_image(self, channel: str):
        """Get a single channel image (R, G, or B).

        Args:
            channel (str): The color channel to extract ('R', 'G', or 'B').

        Returns:
            Optional[np.ndarray]: The extracted channel image or None if not available.
        """
        if self.original_bgr is None:
            return None
        # Create a copy and zero out other channels manually
        bgr = self.original_bgr
        h, w = bgr.shape[:2]
        # Allocate a new image
        result = [[[0, 0, 0] for _ in range(w)] for _ in range(h)]
        # Channel mapping: B=0, G=1, R=2 (OpenCV)
        idx = {"B": 0, "G": 1, "R": 2}[channel]
        for y in range(h):
            row_src = bgr[y]
            row_dst = result[y]
            for x in range(w):
                val = int(row_src[x][idx])
                # Place value only in selected channel
                if idx == 0:
                    row_dst[x][0] = val
                elif idx == 1:
                    row_dst[x][1] = val
                else:
                    row_dst[x][2] = val
        # Convert nested list to OpenCV matrix (uint8)
        import numpy as np  # as OpenCV returns numpy anyway.

        return np.array(result, dtype="uint8")

    def reduce_to_dimensions(self, target_w: int, target_h: int):
        """Reduce image to target_w x target_h using manual nearest neighbor then center
        inside original canvas keeping canvas size constant.

        Args:
            target_w (int): The target width.
            target_h (int): The target height.
        Raises:
            ValueError: If target dimensions are invalid.
        """
        if self.original_bgr is None:
            return None
        import numpy as np

        src = self.original_bgr
        h, w = src.shape[:2]
        if not (1 <= target_w <= w and 1 <= target_h <= h):
            raise ValueError(f"Target dimensions must be within (1..{w}) x (1..{h}).")
        # Manual nearest neighbor sampling
        reduced = [[[0, 0, 0] for _ in range(target_w)] for _ in range(target_h)]
        for y in range(target_h):
            src_y = int(y / (target_h - 1) * (h - 1)) if target_h > 1 else 0
            row_dst = reduced[y]
            row_src = src[src_y]
            for x in range(target_w):
                src_x = int(x / (target_w - 1) * (w - 1)) if target_w > 1 else 0
                b, g, r = row_src[src_x]
                row_dst[x][0] = int(b)
                row_dst[x][1] = int(g)
                row_dst[x][2] = int(r)
        canvas = [[[0, 0, 0] for _ in range(w)] for _ in range(h)]
        off_x = (w - target_w) // 2
        off_y = (h - target_h) // 2
        for y in range(target_h):
            row_canvas = canvas[off_y + y]
            row_reduced = reduced[y]
            for x in range(target_w):
                row_canvas[off_x + x] = row_reduced[x]
        return np.array(canvas, dtype="uint8")


def bgr_to_photo(bgr):
    """Convert a BGR image array to a Tkinter PhotoImage.

    Args:
        bgr (np.ndarray): The BGR image array.

    Returns:
        ImageTk.PhotoImage: The PhotoImage object or None if conversion fails.
    """
    if bgr is None:
        return None
    import numpy as np

    # BGR to RGB manually
    h, w = bgr.shape[:2]
    rgb = [[[0, 0, 0] for _ in range(w)] for _ in range(h)]
    for y in range(h):
        row_bgr = bgr[y]
        row_rgb = rgb[y]
        for x in range(w):
            b, g, r = row_bgr[x]
            row_rgb[x][0] = int(r)
            row_rgb[x][1] = int(g)
            row_rgb[x][2] = int(b)
    rgb_np = np.array(rgb, dtype="uint8")
    # Convert to Tk.PhotoImage via PIL if available, else use workaround
    try:
        from PIL import (
            Image,
            ImageTk,
        )

        img = Image.fromarray(rgb_np, "RGB")
        return ImageTk.PhotoImage(image=img)
    except Exception:
        return None


class App:
    """Main application class for image processing."""

    def __init__(self, root):
        """Initialize the application.

        Args:
            root (tk.Tk): The root Tkinter window.
        """
        self.root = root
        self.root.title("Image Channel & Spatial Reduction")
        self.proc = ImageProcessor()
        self.image_panels = {}

        # Controls frame (path + dimension inputs)
        ctrl = tk.Frame(root, padx=6, pady=6)
        ctrl.pack(side=tk.TOP, fill=tk.X)

        self.path_var = tk.StringVar()
        tk.Entry(ctrl, textvariable=self.path_var, width=50).pack(side=tk.LEFT, padx=4)
        tk.Button(ctrl, text="Browse", command=self.browse).pack(side=tk.LEFT, padx=4)
        tk.Button(ctrl, text="Load", command=self.load).pack(side=tk.LEFT, padx=4)

        tk.Label(ctrl, text="Target W").pack(side=tk.LEFT, padx=2)
        self.target_w_var = tk.StringVar(value="200")
        tk.Entry(ctrl, textvariable=self.target_w_var, width=6).pack(side=tk.LEFT)
        tk.Label(ctrl, text="Target H").pack(side=tk.LEFT, padx=2)
        self.target_h_var = tk.StringVar(value="200")
        tk.Entry(ctrl, textvariable=self.target_h_var, width=6).pack(side=tk.LEFT)
        tk.Button(ctrl, text="Reduce", command=self.do_reduce).pack(
            side=tk.LEFT, padx=4
        )

        # status label
        self.status_var = tk.StringVar(value="Ready")
        status_bar = tk.Label(root, textvariable=self.status_var, anchor="w")
        status_bar.pack(side=tk.BOTTOM, fill=tk.X)

        # Menu bar for viewing images in separate windows
        self.menu = tk.Menu(root)
        file_menu = tk.Menu(self.menu, tearoff=0)
        file_menu.add_command(label="Browse...", command=self.browse)
        file_menu.add_command(label="Load", command=self.load)
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=root.quit)
        self.menu.add_cascade(label="File", menu=file_menu)

        view_menu = tk.Menu(self.menu, tearoff=0)
        view_menu.add_command(
            label="Original", command=lambda: self.open_window("Original")
        )
        view_menu.add_command(
            label="Red Channel", command=lambda: self.open_window("Red Channel")
        )
        view_menu.add_command(
            label="Green Channel", command=lambda: self.open_window("Green Channel")
        )
        view_menu.add_command(
            label="Blue Channel", command=lambda: self.open_window("Blue Channel")
        )
        view_menu.add_command(
            label="Reduced", command=lambda: self.open_window("Reduced")
        )
        self.menu.add_cascade(label="View", menu=view_menu)

        process_menu = tk.Menu(self.menu, tearoff=0)
        process_menu.add_command(
            label="Generate Channels", command=self.update_channels
        )
        process_menu.add_command(label="Reduce (Dimensions)", command=self.do_reduce)
        self.menu.add_cascade(label="Process", menu=process_menu)
        root.config(menu=self.menu)

        # Store image matrices lazily
        self.images = {}
        self.photos = {}

    def browse(self):
        """Open a file dialog to select an image."""
        path = filedialog.askopenfilename(
            title="Select image",
            filetypes=[("Images", "*.png;*.jpg;*.jpeg;*.bmp;*.tif;*.tiff")],
        )
        if path:
            self.path_var.set(path)

    def load(self):
        """Load an image from the specified path."""
        path = self.path_var.get().strip()
        if not path:
            messagebox.showerror("Error", "Please provide a path.")
            return
        try:
            self.proc.load_image(path)
        except Exception as e:
            messagebox.showerror("Load Failed", str(e))
            return
        self.update_channels()

    def update_channels(self):
        """Update the image channels for processing."""
        orig = self.proc.original_bgr
        if orig is not None:
            self.images["Original"] = orig
        for ch_name, code in [
            ("Red Channel", "R"),
            ("Green Channel", "G"),
            ("Blue Channel", "B"),
        ]:
            ch_img = self.proc.channel_image(code)
            if ch_img is not None:
                self.images[ch_name] = ch_img
        self.status_var.set("Channels updated")

    def do_reduce(self):
        """Reduce the image dimensions."""
        if self.proc.original_bgr is None:
            messagebox.showerror("Error", "Load an image first.")
            return
        try:
            tw = int(self.target_w_var.get())
            th = int(self.target_h_var.get())
        except ValueError:
            messagebox.showerror("Error", "Target dimensions must be integers.")
            return
        try:
            reduced = self.proc.reduce_to_dimensions(tw, th)
        except Exception as e:
            messagebox.showerror("Error", str(e))
            return
        if reduced is not None:
            self.images["Reduced"] = reduced
        self.status_var.set(f"Reduced to {tw}x{th} inside canvas")

    def open_window(self, name: str):
        """Open a new window displaying the specified image channel.

        Args:
            name (str): The name of the image channel to display.
        """
        img = self.images.get(name)
        if img is None:
            messagebox.showinfo("Info", f"No image for {name}. Generate/load first.")
            return
        win = tk.Toplevel(self.root)
        win.title(name)
        # Scrollable canvas in case image large
        canvas_frame = tk.Frame(win)
        canvas_frame.pack(fill=tk.BOTH, expand=True)
        canv = tk.Canvas(canvas_frame, highlightthickness=0)
        hbar = tk.Scrollbar(canvas_frame, orient=tk.HORIZONTAL, command=canv.xview)
        vbar = tk.Scrollbar(canvas_frame, orient=tk.VERTICAL, command=canv.yview)
        canv.configure(xscrollcommand=hbar.set, yscrollcommand=vbar.set)
        canv.grid(row=0, column=0, sticky="nsew")
        hbar.grid(row=1, column=0, sticky="we")
        vbar.grid(row=0, column=1, sticky="ns")
        canvas_frame.rowconfigure(0, weight=1)
        canvas_frame.columnconfigure(0, weight=1)
        photo = bgr_to_photo(img)
        if photo is None:
            tk.Label(win, text="(Cannot render: Pillow missing)").pack()
            return
        self.photos[name] = photo
        img_id = canv.create_image(0, 0, anchor="nw", image=photo)
        try:
            h, w = img.shape[:2]
            canv.config(scrollregion=(0, 0, w, h))
            self.status_var.set(f"Opened window: {name} ({w}x{h})")
        except Exception:
            pass


def main():
    root = tk.Tk()
    app = App(root)
    root.mainloop()


if __name__ == "__main__":
    main()
