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

package com.jiftui.demo;

import com.jiftui.appkit.delegates.NSApplication;
import com.jiftui.appkit.windowing.Notification;
import com.jiftui.swiftui.View;

public class SampleApp extends NSApplication {

    public SampleApp() {
        new View()
        .task(() -> {

        })
        .onAppear(() -> {

        });
    }

    @Override
    public void applicationWillFinishLaunching(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillFinishLaunching'");
    }

    @Override
    public void applicationDidFinishLaunching(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidFinishLaunching'");
    }

    @Override
    public void applicationWillHide(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillHide'");
    }

    @Override
    public void applicationDidHide(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidHide'");
    }

    @Override
    public void applicationWillUnhide(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillUnhide'");
    }

    @Override
    public void applicationDidUnhide(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidUnhide'");
    }

    @Override
    public void applicationWillBecomeActive(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillBecomeActive'");
    }

    @Override
    public void applicationDidBecomeActive(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidBecomeActive'");
    }

    @Override
    public void applicationWillResignActive(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillResignActive'");
    }

    @Override
    public void applicationDidResignActive(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidResignActive'");
    }

    @Override
    public void applicationWillUpdate(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillUpdate'");
    }

    @Override
    public void applicationDidUpdate(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationDidUpdate'");
    }

    @Override
    public void applicationWillTerminate(Notification sender) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'applicationWillTerminate'");
    }

    @Override
    public boolean applicationShouldTerminateAfterLastWindowClosed(NSApplication sender) {
        return true;
    }
}
