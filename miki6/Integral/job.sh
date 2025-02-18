#!/bin/bash

#PBS -l walltime=00:00:30, nodes=7:ppn=4
#PBS -N Nik_task
#PBS -q batch


./integral $1 $2 $3 $4
