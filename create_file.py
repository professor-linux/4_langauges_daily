#!/usr/bin/python3

import argparse

parser = argparse.ArgumentParser(
        prog='Create a File',
        description='Creates a file, <filename>, <text>')
parser.add_argument('-f','--filename', type=str)
parser.add_argument('-t','--text', type=str)
args = parser.parse_args()

if args.filename and args.text:
  f = open(args.filename,"at")
  f.write(args.text.replace('\\n','\n'))
  f.close
else:
  parser.print_help()
