/**
 * @author: tourist
 */
import java.io.*
import java.util.*

fun solve(sc: InputReader, out: PrintWriter) {
	val testCases = sc.nextInt()
	for (test in 1..testCases) {
		out.print("Case #$test: ")
        val n = sc.nextInt()
        val m = sc.nextInt()
        var a = Array<String?>(n, {i->""})
        for (i in 0..n-1) {
            a[i] = sc.nextToken()
        }
        var b = Array<String?>(n, {i->""})
        for (i in 0..n-1) {
            b[i] = sc.nextToken()
        }
        var ans = 1234567
        for (cor in 0..n-1) {
            var flip = BooleanArray(m)
            var cnt = 0
            for (j in 0..m-1) {
                if (a[0]!!.charAt(j) != b[cor]!!.charAt(j)) {
                    flip[j] = true
                    cnt++
                } else {
                    flip[j] = false
                }
            }
            var c = Array<String>(n, {i->""})
            for (i in 0..n-1) {
                var w = ""
                for (j in 0..m-1) {
                    if (flip[j]) {
                        w = w + (if (a[i]!!.charAt(j) == '0') '1' else '0')
                    } else {
                        w = w + a[i]!!.charAt(j)
                    }
                }
                c[i] = w
            }
            var d = Array<String>(n, {i->""})
            for (i in 0..n-1) {
                d[i] = b[i]!!
            }
            Arrays.sort(c)
            Arrays.sort(d)
            var ok = true
            for (i in 0..n-1) {
                if (!c[i].equals(d[i])) {
                    ok = false
                    break
                }
            }
            if (ok) {
                if (cnt < ans) {
                    ans = cnt
                }
            }
        }
        if (ans == 1234567) {
            out.println("NOT POSSIBLE")
        } else {
            out.println(ans)
        }
	}
}

fun main(args: Array<String>) {
    val taskName = "a"
	var input: InputStream = System.`in`
	var output: OutputStream = System.out
	val file = File("src/" + taskName + "/in")
	if (file.canRead()) {
		input = FileInputStream(file)
		output = FileOutputStream("src/" + taskName + "/out")
	}
	val sc = InputReader(input)
	val out = PrintWriter(output)
	solve(sc, out)
	out.close()
}

class InputReader (r: InputStream) {
	private val br = BufferedReader(InputStreamReader(r))
	private var st: StringTokenizer? = null

	fun nextToken(): String? {
		while (st == null || !st!!.hasMoreTokens()) {
			val line = br.readLine()
			if (line == null) {
				return null
			}
			st = StringTokenizer(line)
		}
		return st!!.nextToken()
	}

    fun nextInt(): Int {
        return nextToken()!!.toInt()
    }

    fun nextLong(): Long {
        return nextToken()!!.toLong()
    }

	fun nextDouble(): Double {
		return nextToken()!!.toDouble()
	}
}
