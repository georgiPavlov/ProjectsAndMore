/**
 * Created by Georgi on 9/29/2015.
 */

public class ShipFactory {
    public Ship inShip;
    public ShipFactory(String shipIs){
        if(shipIs.equals("F")){
           inShip = returnFast();
        }else {
            inShip = returnBig();
        }

    }

    private Ship returnFast(){
       Ship shipFast= new ShipFast();
        System.out.print(shipFast.getName());
        return shipFast;
    }

    private Ship returnBig(){
        Ship bigFast= new ShipBig();
        System.out.print(bigFast.getName());
        return bigFast;
    }




}
