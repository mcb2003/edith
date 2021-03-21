#*  Edith: Yet another text editor
#Copyright (C) 2021 Michael Connor Buchan
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
#author: Michael Connor Buchan <mikey@blindcomputing.org.>

cmake_minimum_required(VERSION 3.10)
project(edith VERSION 0.1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_definitions(-D_POSIX_C_SOURCE=200809L)

add_subdirectory(display)
add_subdirectory(editor)

add_executable(edith main.c)
target_link_libraries(edith PRIVATE display editor)
install(TARGETS edith DESTINATION bin)
