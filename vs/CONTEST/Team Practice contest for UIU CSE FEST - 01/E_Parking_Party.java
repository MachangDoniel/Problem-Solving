import java.io.*;
import java.util.*;

public class Main {
    public static final int MOD = 1_000_000_007;
    public static final int INF = Integer.MAX_VALUE;

    static InputReader scanner;
    static PrintWriter out;

    public static void main(String[] args) {
        scanner = new InputReader(System.in);
        out = new PrintWriter(System.out);

        int t = 1;//scanner.nextInt();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void move(char[][] grid, int n, int m, int i, int j, int incI, int intJ){
        while (i < n && j < m && i >= 0 && j >= 0){
            if(grid[i][j] == 'o') return;

            grid[i][j] = 'p';
            i += incI;
            j += intJ;
        }
    }

    private static void solve() {

        final int n = scanner.nextInt();
        final int m = scanner.nextInt();

        char[][] grid = new char[n][m];

        for(int i=0; i<n; i++){
            grid[i] = scanner.next().toCharArray();
        }

        long ans = 0L;
        for(int i=0; i<n; i++){
            move(grid, n, m, i, 0,0,1);
            move(grid, n, m, i, m-1,0,-1);
        }
        for(int j=0; j<m; j++){
            move(grid, n, m, 0,j, 1, 0);
            move(grid, n, m, n-1,j, -1, 0);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'p') ans++;
            }
        }

        out.println(ans);
    }


    private static int[] take(int n){
        final int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        return arr;
    }

    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object obj) {
            if(this == obj) return true;

            if(obj == null || getClass() != obj.getClass()) return false;

            Pair pair = (Pair) obj;
            return first == pair.first && second == pair.second;
        }

        @Override
        public String toString() {
            return first+" "+second;
        }

        @Override
        public int compareTo(Pair o) {
            if(first == o.first) return Integer.compare(second, o.second);
            return Integer.compare(first, o.first);
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong(){ return Long.parseLong(next()); }
        public double nextDouble(){ return Double.parseDouble(next()); }
    }
}