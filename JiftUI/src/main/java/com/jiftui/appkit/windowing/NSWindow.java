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

package com.jiftui.appkit.windowing;

import com.jiftui.annontations.SwiftClassMode;
import com.jiftui.annontations.SwiftClassType;
import com.jiftui.annontations.SwiftParser;
import com.jiftui.annontations.SwiftParserMode;

// NOTE: This class has missing API features from the original NSWindow API.
// NOTE: Future NSWindow changes will be made once JiftUI is more stable

@SwiftParser(value = SwiftParserMode.PARSER_IGNORE_TYPE)
@SwiftClassType(value = SwiftClassMode.SWIFT_EXTENSION_TYPE)
public abstract class NSWindow {

    public String title;
    public String subtitle;

    public TitleVisibility titleVisibility;
    public boolean titleAppearsTransparent;

    public NSWindow() { }

    @SwiftClassType(value = SwiftClassMode.SWIFT_STRUCT_TYPE)
    public static enum TitleVisibility {
        VISIBLE(0),
        HIDDEN(1);

        TitleVisibility(int i) { }
    }

    @SwiftClassType(value = SwiftClassMode.SWIFT_STRUCT_TYPE)
    public static enum ToolbarStyle {
        AUTOMATIC(0),
        EXPANDED(1),
        PREFERENCE(2),
        UNIFIED(3),
        UNIFIEDCOMPACT(4);

        ToolbarStyle(int i ) { }
    }

    @SwiftClassType(value = SwiftClassMode.SWIFT_STRUCT_TYPE)
    public static enum StyleMask {
        BORDERLESS,
        TITLED,
        CLOSABLE,
        MINIATURIZABLE,
        RESIZABLE,
        TEXTURED_BACKGROUND,
        UNIFIED_TITLE_AND_TOOLBAR,
        FULLSCREEN,
        FULLSCREEN_CONTENTVIEW,
        UTILITY_WINDOW,
        DOC_MODAL_WINDOW,
        NON_ACTIVATING_PANEL,
        HUD_WINDOW;
    }

}
