import java.util.regex.Pattern;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.regex.Matcher;

public class Assn2 {
    public static void main(String args[]){
        //only proceed if filename given
        if(args.length > 0){
            //compile reg ex
            Pattern pattern = Pattern.compile("\\$\\^*(0|([1-9]\\d{0,2})(,\\d{3})*)((\\.\\d{2})|$)");
            
            try{
                //open file
                FileReader fileReader = new FileReader(new File(args[0]));
                BufferedReader bufferedReader = new BufferedReader(fileReader);

                //read each line and determine if match
                String curLine = bufferedReader.readLine();
                while(curLine != null){
                    Matcher matcher = pattern.matcher(curLine);
                    boolean lineMatches = matcher.matches();
                    if(lineMatches){
                        System.out.println(curLine + " is a finanancial quantity");
                    }
                    else{
                        System.out.println(curLine + " is not a financial quantity");
                    }
                    curLine = bufferedReader.readLine();
                }

                //close file stream
                bufferedReader.close();

            }catch(Exception e){
                System.out.println("Error reading from file");
            }
        }
        //print usage and exit if no filename given
        else{
            System.out.println("Usage: java Assn2 [filename]");
        }
    }
}