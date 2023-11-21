use std::env;

use x11::xlib::{XCloseDisplay, XOpenDisplay, XSupportsLocale};

use rwm::die;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() == 2 && args[1] == "-v" {
        die("rwm-0.1.0");
    }

    if args.len() != 1 {
        die("usage: rwm [-v]");
    }

    let suport = unsafe { XSupportsLocale() };

    if suport == 0 {
        die("X does not support locale");
    }

    let display = unsafe { XOpenDisplay(std::ptr::null()) };

    if display.is_null() {
        die("cannot open display");
    }

    rwm::check_other_wm(display);

    unsafe {
        XCloseDisplay(display);
    }
}
