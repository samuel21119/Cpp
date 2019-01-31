#!/bin/bash
#########################################################################
# > File Name: download.sh
# > Author: Samuel
# > Mail: enminghuang21119@gmail.com
# > Created Time: Sun Jan  7 16:58:37 2018
#########################################################################

# Before running this script, please insure that there's no other pdf files
# Modify the range to suit your needs
arrA=$(seq 1 17)
arrB=$(seq 100 129)
volume_range="$arrA $arrB"

mkdir -p PDF

for volume in $volume_range;
do
	for serial in $(seq 0 99);
	do
		problem_id=$((100 * $volume + $serial))
			if [[ ! -f ./PDF/$volume/$problem_id.pdf ]]; then
				wget http://uva.onlinejudge.org/external/$volume/$problem_id.pdf
			fi
	done

	mkdir -p ./PDF/$volume
	mv -n $volume*.pdf ./PDF/$volume 2>/dev/null
done
