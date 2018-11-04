# lem_in
This program get a description of a anthill and find the closest way to move all the ants to a specified room
## Built with
C language
## Installing
- Git clone the repository
- Compile it with `make`
## Make it work
- Make a file like this :
```
# A line with # is a comment, but ## is a rule
# Numbers of ants
15
# rooms description
##start
start 0 0
midroom 0 0
##end
end 0 0
# tunnels between rooms
start-midroom
midroom-end
```
- Run `./lem_in < [file]`
## Author
Simon Galasso
