--Implementation of the UNIX LS utility--

Unix and Unix-like operating systems maintain the idea of a working directory. 
When invoked without arguments, ls lists the files in the working directory. 
If a directory is specified, the files in that directory are listed. 
The arguments may contain a multiple files and directories.

Names starting with "." are hidden. The directory "." refers to the working directory and ".." refers to its parent directory. 
These are not shown by default. With -a (all) hidden files are shown. Using -A (All including "." and ".." ). 
File names specified explicitly (for example ".secret*" ) are always listed.

Without options, ls displays names only. Multiple options may be combined. Common options include:

-l long format, displaying Unix file types, permissions, number of hard links, owner, group, size, last-modified date-time and name. 
If the modified date is older than 6 months the time is replaced with the year. Some implementations add additional flags to permissions.
-h output sizes in human readable format. (e.g., 1K, 234M, 2G, etc.) This option is not part of the POSIX standard, 
although implemented in several systems, e.g., GNU coreutils in 1997,[10] FreeBSD 4.5 in 2002,[11] and Solaris 9 in 2002.[12]
Additional options controlling how items are displayed include:

-R Recursively list items in subdirectories and subdirectories …
-t sort the list by modification time. (default is alphabetically)
-u sort the list by last access time.
-c sort the list by last attribute (status) change time.
-r reverse the order, for example most recent time last.
--full-time to show times with seconds and milliseconds instead of down to the minute.
-1 one entry per line.
-m Stream format; list items across the page, separated by commas.
-g include group but not owner
-o include owner but not group (when combined with -g both group and owner are suppressed)
-d shows information about a directory or symbolic link, rather than the contents of a directory or the link's target.
-F append a "/" to directory names and a "*" to executable files
