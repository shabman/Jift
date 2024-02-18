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

package com.jiftui.swiftui;

import com.jiftui.annotations.SwiftClassMode;
import com.jiftui.annotations.SwiftClassType;
import com.jiftui.annotations.SwiftConstruct;
import com.jiftui.annotations.SwiftVersionSupport;

import com.jiftui.swiftui.annotations.ViewBuilder;
import com.jiftui.swiftui.annotations.ViewFuncCallback;

@SwiftVersionSupport(
    iOS     = 13.0,
    macOS   = 10.15,
    tvOS    = 13.0,
    watchOS = 6.0
)
@SwiftClassType(SwiftClassMode.SWIFT_PROTOCOL_TYPE)
public class View {
    @ViewBuilder public View body;

    @SwiftConstruct(hideConstructor = true)
    public View() { }

    public native View task(ViewFuncCallback onAction);
    public native View onAppear(ViewFuncCallback onAction);
}
