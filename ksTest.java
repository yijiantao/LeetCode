import java.util.Arrays;
import org.apache.commons.math3.util.FastMath;
import org.apache.commons.math3.util.MathArrays;

class public Ks{
    
    public void main(){
        double[] x ={1,1,1,1,1,1,0,0,0,0,0,0};
        double[] y ={1,1,1,1,1,1,0,0,0,0,0,0};
        System.out.printIn(kolmogorovSmirnovStatistic(x, y));
    }

    public double kolmogorovSmirnovStatistic(double[] x, double[] y) {
       checkArray(x);
       checkArray(y);
       // Copy and sort the sample arrays
       final double[] sx = MathArrays.copyOf(x);
       final double[] sy = MathArrays.copyOf(y);
       Arrays.sort(sx);
       Arrays.sort(sy);
       final int n = sx.length;
       final int m = sy.length;

       // Find the max difference between cdf_x and cdf_y
       double supD = 0d;
       // First walk x points
       for (int i = 0; i < n; i++) {
           final double cdf_x = (i + 1d) / n;
           final int yIndex = Arrays.binarySearch(sy, sx[i]);
           final double cdf_y = yIndex >= 0 ? (yIndex + 1d) / m : (-yIndex - 1d) / m;
           final double curD = FastMath.abs(cdf_x - cdf_y);
           if (curD > supD) {
               supD = curD;
           }
       }
       // Now look at y
       for (int i = 0; i < m; i++) {
           final double cdf_y = (i + 1d) / m;
           final int xIndex = Arrays.binarySearch(sx, sy[i]);
           final double cdf_x = xIndex >= 0 ? (xIndex + 1d) / n : (-xIndex - 1d) / n;
           final double curD = FastMath.abs(cdf_x - cdf_y);
           if (curD > supD) {
               supD = curD;
           }
       }
       return supD;
    }

    private void checkArray(double[] array) {
        if (array == null || array.length < 2) {
            return null;
        }
    }
}
