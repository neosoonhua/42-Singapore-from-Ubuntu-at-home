#!/bin/bash
while read -r xx yy
do
	printf "%s %s\n$xx$yy"
done < test.c