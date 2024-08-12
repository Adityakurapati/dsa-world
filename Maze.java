import java.util.ArrayList;

class Maze {
        public static void main(String a[]) {
                // Print the number of ways to solve the maze
                System.out.println(solve(3, 3));

                // Print all possible paths to solve the maze
                System.out.println(solveMaze("", 3, 3));
                String routes[][] = {
                                { "route", "route", "route" }, { "route", "river", "route" },
                                { "route", "route", "route" }
                };
                mazeRestrict("", routes, 0, 0);
        }

        // Function to count the number of ways to solve the maze
        public static int solve(int r, int c) {
                if (r == 1 || c == 1) {
                        return 1;
                }

                int left = solve(r - 1, c);
                int right = solve(r, c - 1);
                return left + right;
        }

        // Function to find all possible paths in the maze
        public static ArrayList<String> solveMaze(String p, int r, int c) {
                if (r == 1 && c == 1) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }

                ArrayList<String> paths = new ArrayList<>();
                ArrayList<String> pathsRight = new ArrayList<>();

                if (r > 1 && c > 1) {
                        paths.addAll(solveMaze(p + "D", r - 1, c - 1));
                }
                if (r > 1) {
                        paths.addAll(solveMaze(p + "V", r - 1, c));
                }

                if (c > 1) {
                        paths.addAll(solveMaze(p + "H", r, c - 1));
                }

                return paths;
        }

        public static ArrayList<String> solveMazeRiver(String p, int r, int c) {
                if (r == 1 && c == 1) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }
                if (r == 1 && c == 1) {
                        ArrayList<String> list = new ArrayList<>();
                        list.add(p);
                        return list;
                }

                ArrayList<String> paths = new ArrayList<>();

                if (r > 1 && c > 1) {
                        paths.addAll(solveMaze(p + "D", r - 1, c - 1));
                }
                if (r > 1) {
                        paths.addAll(solveMaze(p + "V", r - 1, c));
                }

                if (c > 1) {
                        paths.addAll(solveMaze(p + "H", r, c - 1));
                }

                return paths;
        }

        public static void mazeRestrict(String p, String[][] mazel, int r, int c) {
                if (r == mazel.length - 1 && c == mazel[0].length - 1) {
                        System.out.println(p);
                        return;
                }

                if (mazel[r][c] == "river") {
                        return;
                }
                if (r < mazel.length - 1) {
                        mazeRestrict(p, mazel, r + 1, c);
                }
                if (c < mazel.length - 1) {
                        mazeRestrict(p, mazel, r, c + 1);
                }

        }

        public static void mazeRestrictAllDirections(String p, String[][] mazel, int r, int c) {
                if (r == mazel.length - 1 && c == mazel[0].length - 1) {
                        System.out.println(p);
                        return;
                }

                mazel[r][c] = "river";

                if (r < mazel.length - 1) {
                        mazeRestrictAllDirections(p + "D", mazel, r + 1, c);
                }
                if (c < mazel.length - 1) {
                        mazeRestrictAllDirections(p + "R", mazel, r, c + 1);
                }
                if (r > 0) {
                        mazeRestrictAllDirections(p + "U", mazel, r - 1, c);
                }
                if (c > 0) {
                        mazeRestrictAllDirections(p + "L", mazel, r, c - 1);
                }

                mazel[r][c] = "route";
        }

}
