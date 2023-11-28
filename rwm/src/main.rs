use std::{thread, time::Duration};

use x11::xlib::{
    AspectRatio, ExposureMask, PMaxSize, PMinSize, Window, XCloseDisplay, XCreateSimpleWindow,
    XDefaultRootWindow, XEvent, XMapWindow, XNextEvent, XOpenDisplay, XSelectInput,
    XSetNormalHints, XSetTransientForHint, XSizeHints, XStoreName, XSupportsLocale, _XDisplay,
};
use libc;

use rwm::die;

fn transient(display: *mut _XDisplay) {
    unsafe {
        let locale = libc::setlocale(libc::LC_CTYPE, "".as_ptr());
        println!("locale {:p}", locale);
        println!("{:p}", display);
        let mut size_hints = XSizeHints {
            flags: PMinSize | PMaxSize,
            x: 0,
            y: 0,
            width: 0,
            height: 0,
            min_width: 400,
            min_height: 400,
            max_width: 400,
            max_height: 400,
            base_width: 400,
            base_height: 400,
            width_inc: 0,
            height_inc: 0,
            win_gravity: 0,
            min_aspect: x11::xlib::AspectRatio { x: 0, y: 0 },
            max_aspect: AspectRatio { x: 0, y: 0 },
        };
        let size_ptr = &mut size_hints as *mut XSizeHints;

        println!("{:p}", size_ptr);
        // set as a root default windows
        let root_window = XDefaultRootWindow(display);
        println!("root window: {}", root_window);
        // create a windows and put it in the display in default window
        let window = XCreateSimpleWindow(display, root_window, 100, 100, 400, 400, 0, 0, 0);

        println!("window: {}", window);
        XSetNormalHints(display, window, size_ptr) as u64;
        XStoreName(display, window, "floating".as_ptr());
        XMapWindow(display, window);
        XSelectInput(display, window, ExposureMask);

        let mut event = XEvent { type_: 1 };

        // start event loop
        loop {
            XNextEvent(display, &mut event as *mut XEvent);
        //    thread::sleep(Duration::from_secs(1));
            println!("event: {:?}", event);
        }
    }
}

fn main() {
    let support = unsafe { XSupportsLocale() };

    println!("support {}", support);

    if support == 0 {
        die("X does not support locale");
    }

    let display = unsafe { XOpenDisplay(std::ptr::null()) };

    if display.is_null() {
        die("cannot open display");
    }

    transient(display);
    // rwm::check_other_wm(display);
    //

    println!("closing window");
    unsafe {
        XCloseDisplay(display);
    }
}
