import java.util.*;
import java.lang.*;
public class GenerateSwarm {
    ArrayList<Particle> swarm = new ArrayList<Particle> ();
    int swarm_size;
    public GenerateSwarm (){
    	swarm_size = 10;
    }
    public GenerateSwarm (int size){
        swarm_size = size;
    }
    public void generateSwarm (){
        for (int ii = 0; ii < swarm_size; ii++){
            Particle p = new Particle ();
            p.setX(generateNum(3));
            p.setY(generateNum(2));
            System.out.println ("p.getX() >>> " + p.getX());
            System.out.println ("p.getY() >>> " + p.getY());
        }
    }
    public double generateNum (int bound){
        //Random rand = new Random(1);
    	return (Math.random () * bound) * (Math.random()*100 < 50 ? -1 : 1);
    }
    public double generateSolution (Particle p){
    	return (4-2.1*Math.pow(p.getX(),2)+(Math.pow(p.getX(),4)/3))*Math.pow(p.getX(),2) + p.getX()*p.getY()+ (-4+4*Math.pow (p.getY(),2))*Math.pow(p.getY(),2);
    }
}