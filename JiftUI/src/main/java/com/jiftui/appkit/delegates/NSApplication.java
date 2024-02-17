package com.jiftui.appkit.delegates;

import com.jiftui.annontations.SwiftSyntaxStyle;
import com.jiftui.appkit.windowing.Notification;

public abstract class NSApplication {

    public NSApplication() { }

    public abstract void applicationWillFinishLaunching     (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidFinishLaunching      (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillHide                (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidHide                 (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillUnhide              (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidUnhide               (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillBecomeActive        (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidBecomeActive         (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillResignActive        (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidResignActive         (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillUpdate              (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidUpdate               (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillTerminate           (@SwiftSyntaxStyle(value = "HiddenLabel") Notification sender);

    // NOTE: Missing DCSP Func and DCOS Func
}
