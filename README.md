# getmap
Simple command line tool to discover open tcp ports in a range of ip addresses 

## About
I saw someone mention nmap in a joke 'hackers' subreddit and I thought it would be fun to try and make my own.

## Building
Currently this only runs on linux systems, but any major linux distribution will work. \
To run on windows, install [wsl](https://learn.microsoft.com/en-us/windows/wsl/) in powershell or cmd:
```
wsl --install
```

This will install Ubuntu by default, to specify a distro run
```
wsl --install -d <DistroName>
```

To build, first clone the repo:
```
git clone https://github.com/ansht2000/getmap.git
```

Then cd into the created directory, it should be called getmap, and simply run:
```
make getmap
```

This will create the getmap executable, which you can run with 
```
./getmap <port> [begin_ip_addr] [end_ip_addr]
```