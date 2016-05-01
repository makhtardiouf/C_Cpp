import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int jX = ans.nextInt();
        int jY = ans.nextInt();
        long jValue = ans.nextLong();
        int pX = ouf.nextInt();
        int pY = ouf.nextInt();
        long pValue = ouf.nextLong();

        int n = inf.nextInt();
        int m = inf.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = inf.nextInt();
            }
        }
        if (pX <= 0 || pX > n) {
            return outcome(WA, String.format("Coordinate x is out of bounds: %d", pX));
        }
        if (pY <= 0 || pY > m) {
            return outcome(WA, String.format("Coordinate y is out of bounds: %d", pY));
        }
        long value = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                value += (long) a[i][j] * 2 * (Math.abs(i - pX + 1) + Math.abs(j - pY + 1) + 1);
            }
        }
        if (value != pValue) {
            return outcome(WA, String.format("Participant returned wrong number of moves for his coordinates: expected %d, found %d", value, pValue)); 
        }
        if (value > jValue) {
            return outcome(WA, String.format("Jury has better answer: expected %d, found %d", jValue, value));
        }
        if (value < jValue) {
            return outcome(FAIL, String.format("Participant found better answer: expected (%d %d %d), found (%d %d %d)", jX, jY, jValue, pX, pY, pValue));
        }
        return outcome(OK, String.format("Correct answer, (%d %d %d)", pX, pY, pValue));
    }
}


