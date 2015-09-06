#!/bin/bash
gcc SML.c example.c
if [ $? == 0 ]; then
	echo 'Done building.'
fi
