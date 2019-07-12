#makefile
caso1.png: inicial.txt futura.txt futura2.txt Plots_Difusion.py Difusion.cpp
	python Plots_Difusion.py
%.txt: a.out
	./a.out
a.out: Difusion.cpp
	g++ Difusion.cpp

caso2.png: inicialc2.txt futurac2.txt futura2c2.txt Plots_Difusion.py Difusion.cpp
	python Plots_Difusion.py
%.txt: a.out
	./a.out
a.out: Difusion.cpp
	g++ Difusion.cpp

caso3.png: inicialc3.txt futurac3.txt futura2c3.txt Plots_Difusion.py Difusion.cpp
	python Plots_Difusion.py
%.txt: a.out
	./a.out
a.out: Difusion.cpp
	g++ Difusion.cpp