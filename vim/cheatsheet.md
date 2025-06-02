### Move
`<Ctrl-e>` move your cursor upward half a screen.
`<Ctrl-d>` move your cursor downward half a screen.


### Option
`:set no<option>` - Unset the option.
`:set <option>!` - Toggle the option.
`:set <option>?` - Return the option's value.
`set <option>=<value>` - Set a Value `<value>`(string or number).
`set <option>+=<value>` - Add the Value `<value>` for a number option, append a string `<value>` for a string option.
`set <option>-=<value>` - Subtract the Value `<value>` for a number option, delete the string `<value>` for a string option.
`set <option>&` - Reset the option to its default value.


### Buffer
Not all buffers are displayed in the buffer list. To display unlisted buffers,you can use the command `:buffers!` or `:ls!`. You'll see unlisted buffer with an indicator `u` just after its ID.

`<Ctrl-^>` - Switch to the alternate buffer. It's Indicated in your buffer list with the symbol `#`.
`badd <filename>` - Add `<filename>` to the buffer list.

### Mapping keystrokes
You can use mapping commands for every Vim Mode:
- `:nmap` - Create new mapping for NORMAL mode.
- `inmap` - Create new mapping for INSERT mode.
- `:xmap` - Create new mapping for VISUAL mode.
- `:cmap` - Create new mapping for COMMAND-LINE mode.

Non-recursive mapping
- `:nnoremap` - Create new mapping for NORMAL mode (non recursive).
- `inoremap` - Create new mapping for INSERT mode (non recursive).
- `:vnoremap` - Create new mapping for VISUAL mode (non recursive).
- `:cnoremap` - Create new mapping for COMMAND-LINE mode (non recursive).


### Jump list
Each time we use a jump motion, the position of the cursor before the jump is saved in the jump list. You can move through this jump list with the following keystrokes:

- `<Ctrl-o>` Go to the previous cursor position.
- `<Ctrl-i>` Go to the next cursor position.

To display your jump list, use the command `:jumps`.


### Single Repeat
- `.` - Repeat the last change.
- `@:`- Repeat the last command executed.


### Command Line Window
You can access the history of your Ex commands directly in Vim:

- `q:` - Open command line history.
- `q/` and `q?` - Open search history.
- `<Ctrl-f>` - Open command line history while in COMMAND LINE mode.

Using the keystrokes above, you can modify any command-line you want and execute it with `ENTER`.


### Useful "g" Keystrokes
- `gf` - Edit the file located at the file-path under your cursor
- `gx` - Open the file located at the file-path under your cursor, It works with URLs too. It will open your favorite browser and load the website.
- `gi` - Move to the last insertion you did and switch to INSERT mode.
- `gv` - Start VISUAL mode and use the selection made during the last VISUAL mode.
- `gu` - Lowercase using a motion (for example, `guiw`).
- `gU` - Uppercase using a motion (for example, `gUiw`).


### Ranges
`.` - Represent the current line.
`&` - Represent the last line of the current buffer.
`%` - Represent the entire file.
`*` - Use the last selection you've made during the last VISUAL mode.


### Quickfix Lists
You can think of a quickfix list as a set of positions in one or multiple files.

- `:copen` or `:cope` - Open a window(with a special buffer) to show the current quickfix list. Hit `Enter` to move to the position of the selected entry of the quickfix list in the quickfix window.
- `:cl` or `:clist` - Display all valid entries of the current quickfix list.
- `:cc <number>` - Move to the `<number>`th entry of the current quickfix list.
- `:cdo <cmd>` - Execute a command `<cmd>` on each valid entry of the current quickfix list.
- `cexpr <expr>` or `cex <expr>` - Create a quickfix list using the result of evaluating the Vimscript expression `<expr>` (for example, using `:cex []` to empty the current quickfix list).


### Vim's Registers
- `:register` or `reg` - Display the content of your registers.
- `"<reg>` - This keystroke specifies the register `<reg>` to be read or written.

- `""` -  The unnamed register
- `"0` - contains the content of the last yank.
- `".` - contains the last inserted text.
- `"%` - contains the name of the current file.
- `":` - contains the most recent command line executed.
- `"=` - Store the result of an expression.
- `"_` - The black hole register

- `<Ctrl-r> <reg>` - You can use `<Ctrl-r> <reg>` to put the content of register `<reg>` in your current buffer.


### The Substitute Commands
`:s/pattern/replacement/flags`

There's another element, represented here with a slash `/`: the separator. It doesn't have to be a slash, it can be any character except:
- An alphanumerical(`a-z`, `A-Z`, `0-9`).
- A double quote `"`.
- A pipe `|`.


- To have access to all regex metacharacters, you can prefix your pattern with `\v`(`v`ery magic).
- To have access to almost all regex metacharacters (except `(`, `)` and `|`), use the command `:sm` instead of `:s`(`s`ubstitue `m`agic).
- To have access to none of the metacharacters (except `$`), use `sno` instead of `:s`(`s`ubstitute `no`magic).
- To have access to none of the metacharacters, you can prefix your pattern with `\V`(`V`ery nomagic).

#### Additional Commands
- `:&&` - Repeat the last substitute with its flags.
- `:~` - Repeat the last substitute command with the same replacement, but with the last used search pattern.

```vim
:s/pattern/replacement/
/hello
:~
```
The last command will substitute `hello` with `replacement`.

- `&` - Repeat the last substitute, without its range and its flags.
- `g&` - Repeat the last substitute with the same flags but without the same range (it's global), and replace its pattern with the last search pattern.

#### The Substitutes Flags
Here are some flags which can be useful.
- `&` - Use the flags from the previous substitute command.
- `c` - Ask you to confirm each substitution.
- `g` - Replace all occurrences in each line (not only the first one).
- `i` - The pattern is case-insensitive.
- `I` - The pattern is case-sensitive.
- `n` - Only report the number of match without substitute.


### The Global Command
It works similarly to the substitute command, except that it will execute a command instead of replacing a pattern.

Here's the pattern of the command itself:
```vim
:g/pattern/command
```


### Normal mode Commands
You can give to it some NORMAL mode keystrokes and it will apply therm for you, as if you were hitting therm in NORMAL mode. For example, the following will delete the word under the cursor:
```vim
:norm daw
```

This will lowercase every line containing the pattern `useless`.
```vim
:g/useless/norm gu$
```

If you only want to use Vim's default mapping, you can use `norm!` instead.

### Marks
- `'<mark>` - Move to the first non-blank character of the line where the mark `<mark>` was set.
- `g'<mark>` - Move to the mark `<mark>` without changing the jump list.

Some useful commands for displaying or manipulating marks:
- `:marks` - Display the marks set.
- `:marks <marks>` - Display some specific marks `<marks>`.
- `delmarks <mark>` or `delm <mark>` - Delete the mark `<mark>`.
- `:delmarks!` or `delm!` - Delete all the marks in the range `a-z`.

#### Special Marks
- `g'"` - Move to the position were you've closed the current file for the last time.

### Manipulating Numbers
- `<Ctrl-a>` - Increase the first digit or number on the line.
- `<Ctrl-x>` - Decrease the first digit or number on the line.

- `g<Ctrl-a>` - Same as `<Ctrl-a>` unless you have several lines selected. In that case, the first number of each line will be incremented sequentially.
- `g<Ctrl-x>` - Same as `<Ctrl-x>` unless you have several lines selected. In that case, the first number of each line will be decremented sequentially.


### Sorting Text
`:sort` or `:sor` - Sort lines depending on a range. If no range is given, all lines are sorted, `:sort!` or `sor!` reverse the order.

You can add some options to this command. Here are the most useful ones:
- `i` - Ignore Case.
- `n` - Sort depending on the first decimal on the line.



### Digraphs
- `<Ctrl-k> <char1><char2>` - Insert the digraph represented with the characters `<char1>` and `<char2>`.

**Vim Help**
*:h digraph*
*:h digraph-table*


### Useful Keystrokes In Insert Mode
- `<Ctrl-w>` - Delete the `w`ord under the cursor.
- `<Ctrl-u>` - Delete everything before the cursor.
- `<Ctrl-t>` - Add one indentation.
- `<Ctrl-d>` - `D`elete one indentation.

- `<Ctrl-R> <reg>` - Spit the content of the register `<reg>` as if you typed it.
- `<Ctrl-R> <Ctrl-R> <reg>` - Spit the literal content of the register `<reg>`.
- `<Ctrl-R> <Ctrl-P> <reg>` - Spit the literal content of the register `<reg>` with the correct indentation.

- `<Ctrl-g> u` - Stop the undo sequence.



### Useful Keystrokes In Visual Mode
You can switch between Visual mode linewise and Visual mode blockwise without back to Normal mode with `<Ctrl-v>` and `<Shift-v>`.

- `o` - Move your cursor to the `o`pposite side of the selection.
- `U` - `U`ppercase the selection.


#### Visual Mode Blockwise
- `I` - Insert some content at the beginning of every line selected.
- `A` - Append some content on every line selected after the highlighted area.
- `$A` - Append some content at the end of every line selected.
- `c` - Delete selected lines and begin Insert mode on every line.

### Using Your Shell Commands In Vim
- `:! <cmd>` - Execute the shell command `<cmd>`>
- `:!!` - Repeat the last command executed.
- `:read! <cmd>` or `r! <cmd>` - Execute the command `<cmd>` and insert the output in the current buffer.
- `read!!` or `r!!` - Repeat the last command executed and insert the output in the current buffer.


### Filter
- `:<range>!grep <pattern>` - Every line without the pattern `<pattern>` in current buffer will be disappear.


### Folding
A good way to manage complexity is to hide what we don't need. In that regard, folding can be handy for complex codebases and long files.


#### Creating and deleting folds
These key strokes only work if your foldmethod is set to `manual` of `maker`.

- `zf` - Create a `F`old. It can be used in Visual mode or with a motion.
- `zd` - `d`elete the fold under the cursor (but not the nested ones).
- `zD` - `D`elete the fold under the cursor, including the nested ones.
- `zE` - `E`liminate every fold in the window. It deletes the markers if you foldmethod is et to `marker`.


#### Opening and Closing Folds.
- `za` - Toggle the fold under the cursor.
- `zo` - `o`pen the fold under the cursor.
- `zc` - `c`lose the fold under the cursor.

Uppercase variants of these keystrokes (`zO` for example) can be used to propagate the action to every nested fold.

- `zM` - Close all folds.
- `zR` - Open all folds.


### search
If the option `incseach` is set, it will highlight the search you're doing while typing it.


### Vim Sessions
If you want to save and restore much more than options and global mappings, you can use Vim sessions.

A session is constituted of all the views (a view is collection of settings attached to a window) and the global settings of your current Vim instance.

Use `:mksession <filepath>` or `:mks <filepath>` to create a session and, use `:source <filepath>` to restore a session.

As usual, you can add a bang `!` to the command to overwrite the file if it already exists.


### The files viminfo or shada
Vim also saves information automatically into a file when you close the editor. This file is different depending on what you're using:

- For Vim, it's the viminfo file.
- For Neovim, it's the shada file (for `sh`ared `da`ta).

On Unix systems(Linux and macOS), each file can be found at theses file paths:

- viminfo - `$HOME/.viminfo`
- shada - `$HOME/.local/state/nvim/shada`


### Auto Commands
Auto Commands can automatically run a command when a specific event happens. More precisely, it adds a command to a list of command linked to a precise event. When this event is fired, every command of the list of commands are executed.

- `:autocmd <event>` or `:au <event>` - Output the list of commands executed when the event `<event>` is fired.
- `:autocmd! <event>` or `:au! <event>` - Delete the list of auto commands of the event `<event>`.


### Auto Command Groups
- `augroup` - Output all auto command groups
- `augroup <name>` or `aug <name>` - Create auto command group named `<name>`
- `augroup! <name>` or `aug! <name>` - Delete the group named `<name>`


- `autocmd <group>` or `au <group>` - Output all auto commands in group named `<group>`
- `autocmd! <group>` or `au! <group>` - Delete all auto commands in group named `<group>`


### Ignoring Events
If you want to run a command without firing any event, you can use the command `:noautocmd`.

`:noautocmd w`
