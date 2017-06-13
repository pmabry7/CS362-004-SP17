/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */


public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }
   

   public void iterateOverTestParts(Object [] testParts, int testPartIndex[])
   {
	   int i = 0;
	   int j = 0; 
	   int k = 0;
	   
	   
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //System.out.println(urlVal.isValid("http://www.amazon.com"));

	   assertTrue(urlVal.isValid("http://www.amazon.com"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat.png"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat(1).png"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat_1.png"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat-1.png"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat.png.jpeg"));
	   assertTrue(urlVal.isValid("http://www.amazon.com/images/funnyCat(/).png.jpeg"));


	   assertTrue(urlVal.isValid("http://www.amazon.com:80"));
	   assertTrue(urlVal.isValid("http://amazon.com:80"));
	   
	   assertTrue(urlVal.isValid("http://amazon.com"));
	   assertTrue(urlVal.isValid("http://amazon.com/"));
	   assertTrue(urlVal.isValid("http://amazon.com/images"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funnyCat.png"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funnyCat(1).png"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funnyCat_1.png"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funnyCat-1.png"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funnyCat.png.jpeg"));
	   assertTrue(urlVal.isValid("http://amazon.com/images/funny.Cat.png.jpeg"));

	   assertTrue(urlVal.isValid("http://www.amazon.com:0"));
	   assertTrue(urlVal.isValid("http://amazon.com:0"));
	   
	   
	   assertFalse(urlVal.isValid("http:/www.amazon.com//"));
	   assertFalse(urlVal.isValid("http:/www.amazon.com//.."));
	   assertFalse(urlVal.isValid("http:/www.amazon.com/./"));
	   assertFalse(urlVal.isValid("http:/www.amazon.com/./"));
	   assertFalse(urlVal.isValid("http:/www.amazon.com////"));

	   
	   assertFalse(urlVal.isValid("http://##"));

	   
	   
	   assertFalse(urlVal.isValid("http:/amazon.com"));
	   assertFalse(urlVal.isValid("http//amazon.com"));
	   assertFalse(urlVal.isValid("http///amazon.com"));
	   assertFalse(urlVal.isValid("hp:/amazon.com"));
	   assertFalse(urlVal.isValid("amazon.com"));


	   assertFalse(urlVal.isValid("http:/www.amazon.com"));
	   assertFalse(urlVal.isValid("http//www.amazon.com"));
	   assertFalse(urlVal.isValid("http///www.amazon.com"));
	   assertFalse(urlVal.isValid("hp:/www.amazon.com"));

	   
	   
	   assertFalse(urlVal.isValid("http://www.amazon.com:"));
	   assertFalse(urlVal.isValid("http://www..amazon.com:"));
	   assertFalse(urlVal.isValid("http://www..amazon,com:"));
	   assertFalse(urlVal.isValid("http://amazon.com:"));
	   
	   

	   
	   assertFalse(urlVal.isValid("http://www.amazon.com:-1"));
	   assertFalse(urlVal.isValid("http://amazon.com:-1"));
	   
	   assertFalse(urlVal.isValid("http://www.amazon.com:65534")); 	//invalid URL
	   assertFalse(urlVal.isValid("http://www.amazon.com:70000")); 	//invalid URL
	   assertFalse(urlVal.isValid("http://www.amazon.com:700000"));	//invalid URL
	   assertFalse(urlVal.isValid("http://www.amazon..com:65535")); //invalid URL
	  
	   assertFalse(urlVal.isValid("http://amazon.com:65534")); 		//invalid URL
	   assertFalse(urlVal.isValid("http://amazon.com:70000")); 		//invalid URL
	   assertFalse(urlVal.isValid("http://amazon.com:700000"));		//invalid URL
	   assertFalse(urlVal.isValid("http://amazon..com:65535")); 	//invalid URL

	   assertFalse(urlVal.isValid("http://amazon.com:1000"));
	   
	   assertFalse(urlVal.isValid("http:// "));
	   assertFalse(urlVal.isValid("http:// .com"));
	   assertFalse(urlVal.isValid("http://  .com"));
	   assertFalse(urlVal.isValid("http://www. .com"));
	   assertFalse(urlVal.isValid("http://www...com"));
	   
	   assertFalse(urlVal.isValid("http://www.amazon.com/images/funnyCat(//).png.jpeg"));

	   System.out.println("---PORT NUMBER TESTING---");
	   	
	   for(int i = 0; i < 1000; i++)
	   {
		   assertTrue(urlVal.isValid("http://amazon.com:" + String.valueOf(i)));
	   }
	   
	   System.out.println(" 'http://amazon.com:' + String.valueOf(i) from i = 0 thru i = 999 all returned valid URLs correctly");

	   
	   for(int i = 1000; i < 65536; i++)
	   {
		   
		   assertFalse(urlVal.isValid("http://amazon.com:" + String.valueOf(i)));
	   }
	   
	   System.out.println(" 'http://amazon.com:' + String.valueOf(i) from i = 1000 thru i = 65535 all returned invalid URLs incorrectly ");

	   
	   System.out.println("---PORT NUMBER TESTING FINISHED---");

	   
   }
   
   
   public void testIsValid()
   {
	   System.out.println("Testing isValid function of URL validator: ");
	   System.out.println("Testing validURLs: ");
	   testArray(validURLs, true);
	   
	   System.out.println("Testing invalidURLs: ");
	   testArray(invalidURLs, false);
	   
	   System.out.println("Testing Complete");
   }
   
   public void testArray(String[] strArr, boolean isValid){
	   
	   UrlValidator validator = new UrlValidator();
	   
	   for(int i = 0; i < strArr.length; i++){
		   
		   boolean result = validator.isValid(strArr[i]);
		   
		   assertEquals(isValid, result);
		   
		   if (isValid == result){
			   System.out.printf("%-20s %-5s %-40s %-10s %-5s\n","TEST PASSED!","URL: ", strArr[i], "Result: ", result);			   
		   }
	   }
   }
   
   String[] validURLs = {"https://www.google.com/",
		   			"https://en.wikipedia.org/wiki/URL",
		   			"http://www.amazon.com",
		   			"http://255.255.255.255",
		   			"http://0.0.0.0",
		   			"https://www.google.com/search?q=puppies",
		   			"Flip3.engr.oregonstate.edu:5775",
		   			"Flip3.engr.oregonstate.edu:0",
		   			"Flip3.engr.oregonstate.edu:57",
		   			"Flip3.engr.oregonstate.edu:579",
		   			"http://www.amazon.com:65536"	
		   					   
   };
   String[] invalidURLs = {"httpps://www.google.com/",
		   			"https:/www.google.com",
		   			"https://www.google.c",
		   			"http:/www.google.com",
		   			"http:://www.google.com",
		   			"Flip3.engr.oregonstate.edu:57755",
		   			"flip3..oregonstate.edu",
		   			"Flip3.engr.oregonstate.edu:57755",
		   			"http://www...com",
		   			"http:/www.google.c00",
		   			"://www.google.com",
		   			"http://256.256.256.256",
		   			"http://999.999.999.999"
		   
   };
   
}
