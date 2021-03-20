# Edith Text Editor

For whatever reason, I've always wanted to write a text editor. Maybe it's because it's a pretty complicated class of
program, involving the creation of a user interface, the management of files and large sections of memory and lots of other
system resources; Maybe it's because I feel like I could bring something new to the table in the [accessibility
department](https://thefakevip.xyz); Maybe I think it'll be fun; Perhapse I'm even insane!

Whatever the reason, this is Edith, my interpretation of *the perfect text editor*. It's written in [C17][c17]
using the [ncurses library][ncurses] for terminal display, and the [CMake build system][cmake]. I ultimately intend
for this project to be cross-platform to any system supporting ncurses and an ISO C / POSIX compliant libc, but
some of those GNU extensions ... they're just so useful! :p

[c17]: <https://en.wikipedia.org/wiki/C17_(C_standard_revision)>
[ncurses]: <https://invisible-island.net/ncurses/announce.html>
[cmake]: <https://cmake.org/>

## Inspiration

* I didn't even consider doing this until I read [The Craft of Text Editing by Craig A. Finseth][tcote].
* [vim][vim] / [neovim][neovim], which I use on a daily basis to write everything from code to class notes.
* [Emacs][emacs] and especially [Emacspeak][emacspeak] (yes, I like both text editors, I just don't like Lisp, sorry!).
* The [GLibC Reference Manual][glibc], if you can believe it! I've found that reading the standard library documentation for any language always provokes ideas of programs you can build with it, and ways in which you can implement them.

[tcote]: <https://www.finseth.com/craft/>
[vim]: <https://www.vim.org/>
[neovim]: <https://neovim.io/>
[emacs]: <https://www.gnu.org/software/emacs/>
[emacspeak]: <http://emacspeak.sourceforge.net/>
[glibc]: <https://www.gnu.org/software/libc/manual/>


## Why the Name

Simple. "Edith" has the word "Edit" in it,, and performing an admittedly cursory search through the Debian repos
yielded no results for programs called "edith" (I suppose the rest of the world isn't as crazy as me lol).

## Contributing

Any contributions are welcome and much appreciated, but do bare in mind that this is my passion project, and I have a
pretty rigid idea of *exactly* how Edith should be designed and operate.

This project is also the latest in a [series][inetd] of [projects][libvec] I'm using to teach myself C and the ins and
outs of libc, so if you spot something I'm doing wrong, I would much appreciate it if you submitted an issue or a PR to
tell me.

[inetd]: <https://github.com/mcb2003/inetd>
[libvec]: <https://github.com/mcb2003/libvec>

## License

Copyright &copy; 2021 Michael Connor Buchan

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see
<https://www.gnu.org/licenses/>.

**Author:** [Michael Connor Buchan](mailto:mikey@blindcomputing.org)
