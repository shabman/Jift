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

#ifndef __LIBJIFTCCONF_H__
#define __LIBJIFTCCONF_H__

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#if __cplusplus
#   define JIFTC_API
#else
#   define JIFTC_API extern
#endif

#define JIFTC_INLINE    inline
#define JIFTC_STATIC    static
#define JIFTC_UNUSED(u)

#endif /* __LIBJIFTCCONF_H__ */