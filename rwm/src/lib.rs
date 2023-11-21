use std::ffi::c_int;
use std::process::exit;

use x11::xlib::{BadAccess, BadDrawable, BadMatch, BadWindow, Display, SubstructureRedirectMask, XDefaultRootWindow, XErrorEvent, XSelectInput, XSetErrorHandler, XSync};
use x11rb::protocol::xproto::{CONFIGURE_WINDOW_REQUEST, COPY_AREA_REQUEST, GRAB_BUTTON_REQUEST, GRAB_KEY_REQUEST, POLY_FILL_RECTANGLE_REQUEST, POLY_SEGMENT_REQUEST, POLY_TEXT8_REQUEST, SET_INPUT_FOCUS_REQUEST};

pub fn error_start(mut _d: Display, mut _e: XErrorEvent) {
    unsafe {
        let d_ptr = &mut _d as *mut Display;
        let e_ptr = &mut _e as *mut XErrorEvent;
        x_error_start(d_ptr, e_ptr);
    }
}


pub unsafe extern "C" fn xerror(d: *mut Display, e: *mut XErrorEvent) -> c_int {
    if (*e).error_code == BadWindow
        || (*e).request_code == SET_INPUT_FOCUS_REQUEST && (*e).error_code == BadMatch
        || (*e).request_code == POLY_TEXT8_REQUEST && (*e).error_code == BadDrawable
        || (*e).request_code == POLY_FILL_RECTANGLE_REQUEST && (*e).error_code == BadDrawable
        || (*e).request_code == POLY_SEGMENT_REQUEST && (*e).error_code == BadDrawable
        || (*e).request_code == CONFIGURE_WINDOW_REQUEST && (*e).error_code == BadMatch
        || (*e).request_code == GRAB_BUTTON_REQUEST && (*e).error_code == BadAccess
        || (*e).request_code == GRAB_KEY_REQUEST && (*e).error_code == BadAccess
        || (*e).request_code == COPY_AREA_REQUEST && (*e).error_code == BadDrawable
    {
        return 0;
    }
    eprintln!(
        "dwm: fatal error: request code={}, error code={}",
        (*e).request_code,
        (*e).error_code
    );
    return x_error_start(d, e); /* may call exit */
}

unsafe extern "C" fn x_error_start(_d: *mut Display, _e: *mut XErrorEvent) -> c_int {
    die("another window manager is already running");
    1
}

pub fn check_other_wm(dpy: *mut Display) {
    unsafe {
        XSetErrorHandler(Some(x_error_start));
        /* this causes an error if some other window manager is running */
        XSelectInput(dpy, XDefaultRootWindow(dpy), SubstructureRedirectMask);
        XSync(dpy, 0);
        XSetErrorHandler(Some(xerror));
        XSync(dpy, 0);
    }
}

pub fn die(message: &str) {
    eprintln!("{}", message);
   exit(1);
}