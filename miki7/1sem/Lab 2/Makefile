all: linear.out openmp.out

linear.out: linear.cc
	g++ -o linear.out linear.cc

openmp.out: openmp.cc
	g++ -o openmp.out openmp.cc -fopenmp

run_linear: linear.out
	./linear.out

run_openmp: openmp.out
	./openmp.out

compare: run_linear run_openmp
	diff result.txt result_omp.txt

clean:
	rm *.out result*.txt

