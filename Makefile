CC="g++"

pstl_dir=./src/*
test_dir=./test

output_dir=./build

test_algorithm:
	mkdir -p $(output_dir)
	$(CC) -o  $(output_dir)/algorithm_test $(test_dir)/algorithm_test.cpp $(pstl_dir)
	$(output_dir)/algorithm_test

test: test_algorithm

clean:
	rm -rf $(output_dir)
