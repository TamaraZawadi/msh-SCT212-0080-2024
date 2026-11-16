# Test Plan

**msh - Mini Shell**

## Test cases
| Input | Expected Behavior | Actual Result |
|---|---|---|
|(blank line) | New prompt, no error | Displayed a new prompt `msh[0]>` without an error|
|echo hello world | Prints text; status 0 | Printed `hello world` |
|ls /nonexistent |Error from ls; non-zero status| Displayed `ls: cannot access '/nonexistent': No such file or directory` next prompt showed `msh[2]> `|
|nosuchcommand |Error message; status 127 |`execvp: No such file or directory`; next prompt showed `msh[127]> `|
|cd /tmp then pwd |Prints /tmp |Changed directory to `/tmp` and `pwd` printed `/tmp`; next prompt showed `msh[0]> `|
|sleep 3 & | Prompt returns at once;PID shown |Printed `[1] <PID>` immediately, returned to prompt `msh[0]> `, and reaped child without leaving a zombie|
|echo hi > f.txt then cat f.txt |File contains hi|Created `f.txt` (permissions `0644`) and `cat f.txt` printed `hi`; next prompt showed `msh[0]> `|
|sleep 100 then Ctrl-C | Sleep stops; shell survives;status 130 |Interrupted `sleep 100`, shell remained active, and next prompt showed `msh[130]> ` |
|Ctrl-D at the prompt | Shell exits cleanly|Exited loop cleanly and returned to Kali shell |
|help | Displays built-in command information | Printed built-in command summary; next prompt showed `msh[0]> `|
|echo New Content > f.txt then cat f.txt | Existing file contents are truncated and replaced |Overwrote previous contents of `f.txt` and `cat f.txt` printed `New Content`; prompt showed `msh[0]>`|
|cd (no arguments) then pwd | Changes to $HOME directory ; status 0 | Changed working directory to `/home/zawadi` and `pwd` printed `/home/zawadi`; prompt showed `msh[0]>`|
