import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

public class Check implements Checker {

    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int cAns = ouf.nextInt();
        int jAns = ans.nextInt();
        if (cAns != jAns) {
            return new Outcome(Outcome.Type.WA, String.format("expected: %d, found: %d", jAns, cAns));
        }
        return new Outcome(Outcome.Type.OK, String.format("%d", jAns));
    }
}
