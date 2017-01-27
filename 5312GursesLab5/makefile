hw5: hw5.o 
	gcc hw5.o -o hw5   

hw5.o: hw5.c
	gcc -c hw5.c

run:
	hw5 graph1.txt
	neato -Tps input.gv -o input.ps
	ps2pdf input.ps
	neato -Tps output.gv -o output.ps
	ps2pdf output.ps

clean:
	rm hw5 hw5.o input.ps input.gv output.ps output.gv input.pdf output.pdf	
