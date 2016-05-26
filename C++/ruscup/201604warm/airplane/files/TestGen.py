import random
random.seed("personal7/airplane")

class TestGen:
    def __init__(self):
        self.test_number = 0
    
    def generate_samples(self):
        self.print_test([[0, 0, 0], [0, 1, 0], [0, 0, 0]])
        self.print_test([[2, 0, 0], [0, 0, 0], [0, 2, 0]])

    def generate_min_tests(self):
        self.print_test([[100]])
        self.print_test([[100, 99, 98]])
        self.print_test([[100, 98, 99]])
        self.print_test([[10**6]])
        self.print_test([[2, 3], [1, 2]])
        self.print_test([[2, 3], [100, 2]])

    def generate_hand_tests(self):
        pass

    def generate_random_test(self, n, m, maxvalue=10**6):
        a = [[0 for i in range(m)] for j in range(n)]
        for i in range(n):
            for j in range(m):
                #if (i * m + j) % 300000 == 0:
                #    print('Processing: ' + str(i * m + j))
                a[i][j] = random.randint(0, maxvalue)
        self.print_test(a)

    def generate_max_tests(self, maxn):
        x = []
        for i in range(maxn):
            x.append(10**6)
        self.print_test([x])
        i = random.randint(0, maxn - 1)
        x[i] -= random.randint(1, x[i])
        self.print_test([x])
        x = []
        for i in range(maxn):
            x.append([10**6])
        self.print_test(x)
        i = random.randint(0, maxn - 1)
        x[i][0] -= random.randint(1, x[i][0])
        self.print_test(x)
        x = []
        for i in range(1000):
            y = []
            for j in range(1000):
                y.append(10**6)
            x.append(y)
        self.print_test(x)
        i = random.randint(0, 1000 - 1)
        j = random.randint(0, 1000 - 1)
        x[i][j] -= random.randint(1, x[i][j])
        self.print_test(x)

    def print_test2(self, field):
        self.test_number += 1
        test_name = "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(len(field), len(field[0]), file=test_file)
        print('\n'.join(' '.join(str(element) for element in row) for row in field), file=test_file)
        test_file.close()

    def print_test(self, field):
        self.test_number += 1
        print('Generating test #%d' % self.test_number)

        test_name = "../tests/" + "{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(len(field), len(field[0]), file=test_file)
        print('\n'.join(' '.join(str(element) for element in row) for row in field), file=test_file)
        test_file.close()

    def generate_all_tests(self):
        self.generate_samples()
        self.generate_min_tests()
        self.generate_hand_tests()
        
        maxn = 10**6
        ns = [2, 3, 5, 10]
        nsbig = [1000, maxn]
        for n in ns:
            self.generate_random_test(n, 1000 // n)
            self.generate_random_test(1000 // n, n)
            self.generate_random_test(n, maxn // n)
            self.generate_random_test(maxn // n, n)
        for n in nsbig:
            self.generate_random_test(n, maxn // n)
            self.generate_random_test(maxn // n, n)
        self.generate_max_tests(maxn)

    def generate_all_tests_argv(self, argv):
        pass            

if __name__ == "__main__":
    import os, shutil
    from sys import argv
    if os.path.exists('../tests'):
        print('Directory <<tests>> already exists')
        shutil.rmtree('../tests', ignore_errors=False, onerror=None)
    try:
        os.makedirs('../tests')
    except OSError:
        pass

    import time
    start = time.time()
    writer = TestGen()
    writer.generate_all_tests()
    #writer.generate_all_tests_argv(argv)
    finish = time.time()
    print('All tests were generated. Elapsed time: ', finish - start)