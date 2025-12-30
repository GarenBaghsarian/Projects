import java.util.*;

class Connecting_Point {
    public String kind;
    public String name;
    public double x;
    public double y;

    public Connecting_Point(String kind, String name, double x, double y) {
        this.kind = kind;
        this.name = name;
        this.x = x;
        this.y = y;
    }

    public float distanceTo(Connecting_Point other) {
        return (float) Math.sqrt(Math.pow(x - other.x, 2) + Math.pow(y - other.y, 2));
    }
}

public class HamraGraph {
    static final int max = 30;
    public static Connecting_Point V[];
    public static float E[][] = new float[max][max];

    public static boolean isSubstring(String s, String sub) {
        s = s.toLowerCase();
        sub = sub.toLowerCase();
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            while (j < sub.length() && j + i < s.length() && s.charAt(i + j) == sub.charAt(j))
                j++;
            if (j == sub.length())
                return true;
        }
        return false;
    }

    public static int Extract(String name, String type) { // type is either start or end
        Scanner scn = new Scanner(System.in);
        while (true) {
            for (int i = 0; i < V.length; i++) {
                if (isSubstring(V[i].name, name)) {
                    return i;
                }
            }
            System.out.printf("No such vertex. Please reenter %s: ", type);
            name = scn.nextLine();
        }
    }

    public static void ShortestPath(int start, int dest) {
        if (start == dest) {
            System.out.println("You are already at your destination");
            return;
        }

        int n = V.length;
        float[] d = new float[n];
        int[] parent = new int[n];
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            d[i] = Float.MAX_VALUE;
            parent[i] = -1;
        }

        d[start] = 0;

        for (int k = 0; k < n; k++) {
            int u = -1;
            float best = Float.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                if (!visited[i] && d[i] < best) {
                    best = d[i];
                    u = i;
                }
            }
            if (u == -1)
                break;
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (E[u][v] > 0 && d[u] + E[u][v] < d[v]) {
                    d[v] = d[u] + E[u][v];
                    parent[v] = u;
                }
            }
        }

        if (d[dest] == Float.MAX_VALUE) {
            System.out.printf("No path exists between %s and %s", V[start].name, V[dest].name);
            return;
        }

        int[] path = new int[n];
        int idx = 0;
        int cur = dest;

        while (cur != -1) {
            path[idx++] = cur;
            cur = parent[cur];
        }

        System.out.printf("\nDestination is approximately %dm away:", (int) Math.round(d[dest]));
        System.out.println("\nDirections:");

        int i = idx - 1;
        String prevDir = directionOf(V[path[i]], V[path[i - 1]]);

        while (i > 0) {
            String currentDir = prevDir;
            int meters = 0;
            int lastNode = path[i];

            while (i > 0) {
                Connecting_Point a = V[path[i]];
                Connecting_Point b = V[path[i - 1]];
                String dir = directionOf(a, b);

                if (!dir.equals(currentDir))
                    break;

                meters += (int) E[path[i]][path[i - 1]];
                lastNode = path[i - 1];
                i--;
            }

            System.out.printf("Go %s %d meters to %s %s\n", currentDir, meters, V[lastNode].name, V[lastNode].kind);

            if (i > 0)
                prevDir = directionOf(V[path[i]], V[path[i - 1]]);
        }
        System.out.println("You have reached your destination!");
    }

    private static String directionOf(Connecting_Point a, Connecting_Point b) {
        double dx = b.x - a.x;
        double dy = b.y - a.y;
        if (Math.abs(dx) > Math.abs(dy))
            return dx > 0 ? "right" : "left";
        else
            return dy > 0 ? "up" : "down";
    }

    public static void main(String args[]) {
        Connecting_Point p0 = new Connecting_Point("Intersection", "Emile Eddeh 1", 1.5, 1.25);
        Connecting_Point p1 = new Connecting_Point("Intersection", "Emile Eddeh 2", 2.55, 1.2);
        Connecting_Point p2 = new Connecting_Point("Intersection", "Emile Edde & Nehme Yafet", 4.5, 1.1);
        Connecting_Point p3 = new Connecting_Point("Intersection", "Emile Eddeh 3", 6.8, 1);
        Connecting_Point p4 = new Connecting_Point("Intersection", "Emile Eddeh & Omar Bin Abdul Aziz", 9.55, 0.95);
        Connecting_Point p5 = new Connecting_Point("Intersection", "Baalbak", 6, 2.33);
        Connecting_Point p6 = new Connecting_Point("Restaurant", "Barbar", 9.33, 2.18);
        Connecting_Point p7 = new Connecting_Point("Arcade", "PlayerOne Entertainment", 3.4, 4.95);
        Connecting_Point p8 = new Connecting_Point("Intersection", "Hamra & Nehme Yafet", 4.55, 4.68);
        Connecting_Point p9 = new Connecting_Point("Intersection", "Hamra 1", 6.15, 4.35);
        Connecting_Point p10 = new Connecting_Point("Intersection", "Hamra 2", 7.9, 4.15);
        Connecting_Point p11 = new Connecting_Point("Intersection", "Hamra & Omar Bin Abdul Aziz", 10, 3.8);
        Connecting_Point p12 = new Connecting_Point("Intersection", "Hamra & Cairo", 12, 3.5);
        Connecting_Point p13 = new Connecting_Point("Restaurant", "Sushi Bell", 2.75, 6.45);
        Connecting_Point p14 = new Connecting_Point("Intersection", "Makdisi 1", 3.5, 6);
        Connecting_Point p15 = new Connecting_Point("Intersection", "Makdisi 2", 6.3, 5.65);
        Connecting_Point p16 = new Connecting_Point("Intersection", "Makdisi & Sabra", 8.08, 5.3);
        Connecting_Point p17 = new Connecting_Point("Intersection", "Makdisi & Omar Bin Abdul Aziz", 10.33, 5);
        Connecting_Point p18 = new Connecting_Point("Intersection", "Sidani", 4.5, 8.4);
        Connecting_Point p19 = new Connecting_Point("Ice Cream Shop", "Lima Gelato", 6.7, 7.6);
        Connecting_Point p20 = new Connecting_Point("Intersection", "Souraty & Omar Bin Abdul Aziz", 10.6, 6.83);
        Connecting_Point p21 = new Connecting_Point("Intersection", "Souraty & Cairo", 12.63, 6.3);
        Connecting_Point p22 = new Connecting_Point("Shop", "Eyedeas Smart Optics", 6.9, 9.35);
        Connecting_Point p23 = new Connecting_Point("Intersection", "Omar Bin Abdul Aziz", 11, 9.18);
        Connecting_Point p24 = new Connecting_Point("Building", "AUBMC", 13.33, 8.35);
        Connecting_Point p25 = new Connecting_Point("Intersection", "Bliss 1", 2.5, 10);
        Connecting_Point p26 = new Connecting_Point("Intersection", "Bliss 2", 4.5, 10.35);
        Connecting_Point p27 = new Connecting_Point("Intersection", "Bliss 3", 7.1, 11);
        Connecting_Point p28 = new Connecting_Point("Clinic", "Mohammad Jomaa", 10.5, 10.5);
        Connecting_Point p29 = new Connecting_Point("Intersection", "Bliss & Omar Bin Abdul Aziz", 11.2, 10.4);

        V = new Connecting_Point[] { p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13,
                p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29 };

        int[][] Neighbors = new int[][] {
                { 1, 25 }, { 0, 2, 7 }, { 1, 3, 8 }, { 2, 4 }, { 3, 6 }, { 6, 9 },
                { 4, 5, 11 }, { 1, 8, 14 }, { 2, 7, 9, 18 }, { 5, 8, 10, 15 }, { 9, 11, 16 },
                { 6, 10, 12, 17 }, { 11, 21 }, { 14 }, { 7, 13, 15, 18 }, { 9, 14, 16, 19 },
                { 10, 15, 17 }, { 11, 16, 20 }, { 8, 14, 20, 26 }, { 15, 22 }, { 17, 18, 21, 23 },
                { 12, 20, 24 }, { 19, 27 }, { 20, 24, 29 }, { 21, 23 }, { 0, 26 },
                { 18, 25, 27 }, { 22, 26, 28 }, { 27, 29 }, { 23, 28 }
        };

        System.out.println("Vertices:");
        for (int i = 0; i < max; i++) {
            Connecting_Point vertex = V[i];
            System.out.printf("%d) %s, %s\n", i, vertex.name, vertex.kind);
        }

        System.out.println("\n\nEdges:");
        for (int i = 0; i < max; i++) {
            Connecting_Point original = V[i];
            for (int j = 0; j < Neighbors[i].length; j++) {
                Connecting_Point neighbor = V[Neighbors[i][j]];
                float distance = original.distanceTo(neighbor) * 10;
                E[i][Neighbors[i][j]] = distance;
                System.out.printf("%s, %s, %dm\n", original.name, neighbor.name, (int) distance);
            }
        }

        Scanner scn = new Scanner(System.in);
        System.out.print("\n\nPlease enter Start Location: ");
        int start = Extract(scn.nextLine(), "start location");
        System.out.print("Please enter Destination: ");
        int dest = Extract(scn.nextLine(), "destination");

        ShortestPath(start, dest);
        scn.close();
    }
}
