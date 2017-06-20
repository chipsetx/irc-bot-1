##IRC BOT

this is a simple irc bot written in c.
it was written to test the irc protocol, and it can be used as a base to make a more complex bot.
actually, it only respond hello world, when given the command `!hello`

you can use a file named config.cfg to customise the bot

exemple :
```
name=yourname
host=yourhost
channel=#yourchannel
server=irc.quakenet.org
port=6668
```


##TODO
catch sigterm to free the memory and close socket properly.
eventually make it portable on windows by using windows socket equivalent ...
