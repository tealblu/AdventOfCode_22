calorieCounting:
	g++ -o calorieCounting calorieCounting.cpp elf.cpp

rCalorieCounting:
	./calorieCounting < ccinput.txt

clean:
	rm -f calorieCounting

git: clean
	git add .
	git commit -m "automated commit from makefile"
	git push