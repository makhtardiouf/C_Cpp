import java.io.*;
import java.util.*;

public class TestGen {
    private final boolean FOR_POLYGON = true;

    private void shuffle(List<?> a) {
        Collections.shuffle(a, random);
    }

    class Test {
        public String descr;
        public int[] a;
        public int[] b;

        public Test(Integer[] a, Integer[] b, String descr) {
            this.a = new int[a.length];
            for (int i = 0; i < a.length; ++i)
                this.a[i] = a[i];
            this.b = new int[b.length];
            for (int i = 0; i < b.length; ++i)
                this.b[i] = b[i];
            this.descr = descr;
        }

        public Test(int[] a, int[] b, String descr) {
            this.descr = descr;
            this.a = a;
            this.b = b;
        }

        public int n() {
            return a.length;
        }

        public int m() {
            return b.length;
        }
    }

    int testCount;
    static Random random = new Random(0xCEEECCEE);

    public static final int MAX_N = 1000_00;//10^5
    public static final int MAX_VAL = 1_000_000_000;

    private String folder;
    boolean isSamples = false;

    public void setFolder(String folder) {
        this.folder = folder;
    }

    public void println(PrintWriter writer, int... arr) {
        for (int i = 0; i < arr.length; ++i)
            if (i + 1 == arr.length) writer.println(arr[i]);
            else writer.print(arr[i] + " ");
    }

    public void print(Test test) throws IOException {
        String path = (FOR_POLYGON ?
                String.format("%d",++testCount) :
                String.format("../%s/%02d", folder, ++testCount));

        PrintWriter out = new PrintWriter(path);
        System.out.println("Generating test #" + testCount + ": " + test.descr);
        out.println(test.n() + " " + test.m());
        println(out, test.a);
        println(out, test.b);
        out.close();
    }

    public void genSamples() throws IOException {
        setFolder("tests");
        isSamples = true;

        System.out.println("==== Generating samples ===");

        print(new Test(new int[]{-1, 2, 3, 4, -5},
                new int[]{-5, 4, 10, 2, -1}, "sample1"));

        print(new Test(new int[]{3, -2, 3, -5, -3},
                new int[]{-1, -2, -3, -4, -5,}, "sample2"));
        isSamples = false;
    }

    void genHandleTests() throws IOException {
        print(new Test(new int[]{1}, new int[]{-1, 0, 1}, "handle test1"));
        print(new Test(new int[]{-1}, new int[]{-1, 0, 1}, "handle test2"));
    }

    public void genSubtask(int n) throws IOException {
        setFolder("tests");
        GenQueries queriesSame = (a, m) -> {
            int[] b = new int[m];
            for (int i = 0; i < b.length; ++i)
                b[i] = a[random.nextInt(a.length)];
            return b;
        };


        GenQueries queriesNotSame = (a, m) -> {
            int[] b = new int[m];
            for (int i = 0; i < b.length; ++i)
                b[i] = randMaxVal();
            return b;
        };

        print(genSorted(n, Comparator.naturalOrder(), queriesSame));
        print(genSorted(n, Comparator.naturalOrder(), queriesNotSame));
        print(genSorted(n, Comparator.reverseOrder(), queriesSame));
        print(genSorted(n, Comparator.reverseOrder(), queriesNotSame));

        print(genAlternation(n, queriesSame));
        print(genAlternation(n, queriesNotSame));
        print(genAlternationShuffle(n, queriesNotSame));
        print(genAlternationShuffle(n, queriesNotSame));
        print(genNegAlternate(n));

        print(genWithBounds(n, -MAX_VAL, 0, -MAX_VAL, 0));
        print(genWithBounds(n, -MAX_VAL, 0, 0, MAX_VAL));
        print(genWithBounds(n, 0, MAX_VAL, 0, MAX_VAL));
        print(genWithBounds(n, 0, MAX_VAL, -MAX_VAL, 0));

        print(genWithBounds(n, -MAX_VAL, MAX_VAL / 4, 0, MAX_VAL));
        print(genWithBounds(n, 0, MAX_VAL, -MAX_VAL, MAX_VAL / 4));
        print(genWithBounds(n, -MAX_VAL, MAX_VAL / 2, 0, MAX_VAL));
        print(genWithBounds(n, 0, MAX_VAL, -MAX_VAL, MAX_VAL / 2));

        int pw = maxLog(n);
        int[] sizes = {pw - 1, pw + 1, pw, pw + 1, pw - 1, pw, n, n, n - 1};
        for (Integer size: sizes)
            print(genRandom(size));
    }

    private Test genNegAlternate(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            if (i % 2 == 0) a[i] = randInt(0, MAX_VAL / 2);
            else a[i] = randInt(-MAX_VAL, -MAX_VAL / 2);
        int[] b = new int[n];
        for (int i = 0; i < n; ++i)
            b[i] = randMaxVal();
        return new Test(a, b, "alternate with negatives");
    }

    private int maxLog(int n) {
        int pw = 1;
        while (2 * pw <= n) pw *= 2;
        return pw;
    }

    private int randMaxVal() {
        return randInt(-MAX_VAL, MAX_VAL);
    }


    private Test genAlternationShuffle(int n, GenQueries generator) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = randMaxVal();
        Arrays.sort(a);
        int i = 0;
        int j = (n + 1) / 2;
        shuffle(a, 0, j);
        shuffle(a, j, n);

        int[] arr = new int[n];
        for (int t = 0; t < n; ++t)
            if (t % 2 == 0) arr[t] = a[i++];
            else arr[t] = a[j++];
        int[] b = generator.gen(a, n);
        return new Test(a, b, "alternate with shuffle");
    }

    private void shuffle(int[] a, int from, int to) {
        int[] b = Arrays.copyOfRange(a, from, to);
        Integer[] bInteger = new Integer[b.length];
        for (int i = 0; i < b.length; ++i)
            bInteger[i] = b[i];

        List<Integer> arr = Arrays.asList(bInteger);
        shuffle(arr);
        for (int i = from; i < to; ++i)
            a[i] = arr.get(i - from);
    }

    private Test genAlternation(int n, GenQueries generator) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = randMaxVal();
        Arrays.sort(a);
        int i = 0;
        int j = (n + 1) / 2;
        int[] arr = new int[n];
        for (int t = 0; t < n; ++t)
            if (t % 2 == 0) arr[t] = a[i++];
            else arr[t] = a[j++];
        int[] b = generator.gen(a, n);
        return new Test(a, b, "alternate");
    }

    private Test genWithBounds(int n, int minA, int maxA, int minB, int maxB) {
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < a.length; ++i)
            a[i] = randInt(minA, maxA);
        for (int i = 0; i < b.length; ++i)
            b[i] = randInt(minB, maxB);
        return new Test(a, b, "with bounds for a and b");
    }

    @FunctionalInterface
    public interface GenQueries {
        int[] gen(int[] a, int n);

    }

    private int[] toIntArray(Integer[] a) {
        int[] ret = new int[a.length];
        for (int i = 0; i < ret.length; ++i)
            ret[i] = a[i];
        return ret;
    }

    private Test genSorted(int n, Comparator<Integer> comp, GenQueries generator) {
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; ++i)
            a[i] = randMaxVal();
        Arrays.sort(a, comp);
        int[] arr = toIntArray(a);
        int[] b = generator.gen(arr, n);
        return new Test(arr, b, "sorted");
    }

    public static class Segment {
        public static Segment MAX_SEGMENT = new Segment(1, MAX_VAL);
        int l, r;
        public Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public static Segment randSegment() {
            return randSegment(MAX_SEGMENT);
        }

        public static Segment randSegment(Segment s) {
            int l = randInt(s);
            int r = randInt(s);
            int t;
            if (l > r) {
                t = l;
                l = r;
                r = t;
            }
            return new Segment(l, r);
        }

        public static Segment randOuterSegment(Segment s) {
            int l = TestGen.randInt(1, s.l);
            int r = TestGen.randInt(s.r, MAX_VAL);
            return new Segment(l, r);
        }

        public static int randInt(Segment segment) {
            return TestGen.randInt(segment.l, segment.r);
        }
    }

    private Test genRandom(int n) {
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = randMaxVal();
            b[i] = randMaxVal();
        }
        return new Test(a, b, "random, n = " + n);
    }

    private static int randInt(int l, int r) {
        return random.nextInt(r - l + 1) + l;
    }

    private static int randInt(int n) {
        return random.nextInt(n) + 1;
    }

    public void run() throws IOException {
        if (!FOR_POLYGON)
            new File("../tests").mkdir();

        genSamples();
        genHandleTests();
        genSubtask(1000);
        genSubtask(MAX_N);
    }

    public static void main(String[] args) throws IOException {
        new TestGen().run();
    }

    private int[] genCombine(int n, int k) {
        if (k > n)
            throw new IllegalArgumentException("k > n");

        List<Integer> p = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            p.add(i + 1);
        shuffle(p);
        int[] ret = new int[k];
        List<Integer> sublist = p.subList(0, k);
        for (int i = 0; i < k; ++i)
            ret[i] = sublist.get(i);
        Arrays.sort(ret);
        return ret;
    }

    private int[] genPartitionViaCombine(int n, int[] comb) {
        int k = comb.length + 1;
        int[] ret = new int[k];
        if (k >= 2)
            ret[0] = comb[0];

        for (int i = 1; i + 1 < k; ++i)
            ret[i] = comb[i] - comb[i - 1];
        ret[k - 1] = k >= 2 ?  n - comb[k - 2] : n;
        return ret;
    }

    public int[] genPartition(int sum, int k) {
        int[] comb = genCombine(sum - 1, k - 1);
        return genPartitionViaCombine(sum, comb);
    }

    private int[] genPartitionWithZeroes(int sum, int k) {
        int[] comb = genCombineWithEq(sum, k - 1);
        return genPartitionViaCombine(sum, comb);
    }

    private int[] genCombineWithEq(int n, int k) {
        int[] ret = new int[k];
        for (int i = 0; i < k; ++i)
            ret[i] = randInt(0, n);
        Arrays.sort(ret);
        return ret;
    }
}
