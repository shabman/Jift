/* 
 * This file is part of the JiftUI distribution (https://github.com/shabman/Jift.git)
 * Copyright (c) 2024 Mustafa Malik.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

package com.jiftui.appkit.delegates;

import com.jiftui.annotations.SwiftClassMode;
import com.jiftui.annotations.SwiftClassType;
import com.jiftui.annotations.SwiftMethodParameterStyle;
import com.jiftui.appkit.windowing.Notification;

@SwiftClassType(SwiftClassMode.SWIFT_OBJC_WRAPPER)
public abstract class NSApplication {

    public NSApplication() { }

    public abstract void applicationWillFinishLaunching     (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidFinishLaunching      (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillHide                (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidHide                 (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillUnhide              (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidUnhide               (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillBecomeActive        (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidBecomeActive         (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillResignActive        (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidResignActive         (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillUpdate              (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);
    public abstract void applicationDidUpdate               (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract void applicationWillTerminate           (@SwiftMethodParameterStyle(value = "HiddenLabel") Notification sender);

    public abstract boolean applicationShouldTerminateAfterLastWindowClosed(@SwiftMethodParameterStyle(value = "HiddenLabel") NSApplication sender);



    // NOTE: Missing DCSP Func and DCOS Func
}
