package inheritance;


public class Volume extends Boxweight{
    double volume;

    Volume(Box box){
        this.volume=box.l*box.w*box.h;
    }
}
