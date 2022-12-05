calorieCounting:
	g++ -o calorieCounting calorieCounting.cpp elf.cpp

rCalorieCounting: calorieCounting
	./calorieCounting < ccinput.txt

rps:
	g++ -o rps rockPaperScissors.cpp

rRps: rps
	./rps

clean:
	rm -f rps
	rm -f calorieCounting

git: clean
	git add .
	git commit -m "automated commit from makefile"
	git push