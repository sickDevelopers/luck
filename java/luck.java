class Luck {

    static final int[] dice = new int[] {4, 6, 8, 10, 12, 20};
    static final int ATTEMPTS = 1000000;

    public static void main(String[] args) {
        long start = System.nanoTime();
        Luck.run();
        long end = System.nanoTime();
        System.out.println("Execution time " + ((end -start) / 1e6) + "ms");
    }

    static int throwRandom(int faces) {
        int t = (int)(Math.random() * faces);
        return t;
    }

    static int roll() {
        int tries = 0;
        for (int i = 0; i < Luck.dice.length; i++) {
            boolean found = false;
            while (!found) {
                tries++;
                if (Luck.throwRandom(dice[i]) == dice[i] -1) {
                    found = true;
                } 
            }
        }
        return tries;
    }

    static void run() {
        int min = 10000000;
        int max = 0;
        double avg = 0.0;
        int tries = 0;
        for (int i = 1; i < Luck.ATTEMPTS; i++) {
            int rolls = Luck.roll();
            if (rolls < min) {
                min = rolls;
            }
            if (rolls > max) {
                max = rolls;
            }
            tries += rolls;
            avg = tries / i;
        }

        System.out.println("min "+ min + ", max " + max + ", avg "+ avg +", total "+ tries);
    }

}
