win:
	g++ q.cpp -o temp -w && temp < input.txt && del temp
linux:
	g++ q.cpp -o temp -w && ./temp <input.txt && rm temp