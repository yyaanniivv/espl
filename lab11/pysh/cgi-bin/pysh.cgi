#!/usr/bin/env python

import cgi, shlex
import cgitb; cgitb.enable()  # for troubleshooting
import sys, subprocess

print "Content-type: text/html"
print

print """
<html>
<head><title> Noa espl page !!!!!! ^_^ </title></head>
<body>
"""
form = cgi.FieldStorage()
command = form.getvalue("command", "")
res=""
addr= form.getvalue("dir", "")
#subprocess.call(command)

if command:
  if shlex.split(command)[0]=="cd":
    addr=addr+shlex.split(command)[1]+"/"
#   else:
#     res=subprocess.check_output(command, shell=True)
print """
  <div>$Addr+command: %s</div>
  <div> 
    <form>
    <h2> <s> Motz</s> and Noa and Yaniv's Shell operator:</h2>
    ENTER COMMAND:
      <p>$ <input type="text" name="command"/></p>
    </form>
  </div>

""" % addr+command
#% shlex.split(command)
res=subprocess.check_output(command, shell=True)
print """
  <div><input type=hidden name="dir" value=%s>  </input> </div>
  <div> 
""" % addr

command=addr+command
print """
  <div>result: %s</div>
</body>

</html>
""" % res