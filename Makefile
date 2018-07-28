all: clean reload lint build exec

mkdir_build:
	[ -d ./bin ] | mkdir -p bin

build:
	cd bin;make

exec:
	./bin/evgenij-scherbakov-game

clean:
	rm -rf bin

reload: mkdir_build
	cd bin;cmake ..

fast_build:
	cd bin;make

run: fast_build exec

lint:
	cd bin;make lint

debug: fast_build debug_server

debug-server:
	gdbserver :1234 ./bin/evgenij-scherbakov-game

reformat:
	find src/ -iname *.h -o -iname* .cpp | xargs clang-format -i --style=file

linux_dep:
	sudo apt install libncurses5-dev
 
