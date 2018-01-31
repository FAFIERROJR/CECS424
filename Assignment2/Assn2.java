import java.util.regex.Pattern;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.regex.Matcher;

public class Assn2 {
    public static void main(String args[]){
        if(args.length > 0){
            Pattern pattern = Pattern.compile("\\$\\^*(0|([123456789]|[123456789]\\d|[123456789]\\d\\d)(,\\d\\d\\d)*)((\\.\\d\\d)|$)");
            
            try{
                FileReader fileReader = new FileReader(new File(args[0]));
                BufferedReader bufferedReader = new BufferedReader(fileReader);

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

                bufferedReader.close();

            }catch(Exception e){
                System.out.println("Error reading from file");
            }
        }
        else{
            System.out.println("Usage: java Assn2 [filename]");
        }
    }
}