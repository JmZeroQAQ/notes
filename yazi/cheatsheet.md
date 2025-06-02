### Navigation
- `K` Seek up 5 units in the preview.
- `J` Seek down 5 units in the preview.
- `z` Open directory or file via fzf.

### Selection
- `<Space>` Toggle selection.
- `v` Enter Visual mode (selection mode).
- `V` Enter Visual mode (unset mode).
- `<Ctrl-a>` Select all files>
- `<Ctrl-r>` Inverse selection of all files.
- `<ESC>` Cancel selection.


### File Operations
- `o` or `<Enter>` Open selected files.
- `<Tab>` Show the file information.
- `y` Yank selected files.
- `x` Cut selected files.
- `p` Paste yanked files.
- `P` Paste yanked files(overwrite if the destination exists).
- `Y` or `X` Cancel the yank status.
- `d` Trash selected files.
- `D` Permanently delete selected files.
- `a` Create a file (end with `/` for directories).
- `r` Rename selected files
- `.` Toggle the visibility of hidden files.
- `-` Symlink the absolute path of yanked files.
- `_` Symlink the relative path of yanked files.
- `<Ctrl>` + `-` Hardlink yanked files.


### Copy Paths
- `<c-c>` Copy the file path.
- `<c-d>` Copy the directory path.
- `<c-f>` Copy the file name.
- `<c-n>` Copy the file name without extension.


### Filter files
- `f` Filter files.


### Search files
- `S` Search files by content using `ripgrep`.
- `<ctrl-s>` Cancel the ongoing search.


### Sorting
- `<,-m>` Sort by modified time.
- `<,-M>` Sort by modified time(reverse).
- `<,-b>` Sort by birth time.
- `<,-B>` Sort by birth time(reverse).
- `<,-s>` Sort by size.
- `<,-S>` Sort by size(reverse).
- `<,-n>` Sort naturally.

### Multi-tab
-  `t` Create a new tab with `CWD`.
- `1`, `2`, ..., `9` Switch to the N-th tab.
- `<Ctrl-c>` Close the current tab.
