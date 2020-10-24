import paho.mqtt.client as mqttClient
import time
from datetime import datetime


def on_connect(client, userdata, flags, rc):

    if rc == 0:

        print("Connected to broker")

        global Connected                #Use global variable
        Connected = True                #Signal connection

    else:

        print("Connection failed")

def on_message(client, userdata, message):
    print ("Message received: "  + str(message.payload.decode('utf-8')) + " " +str(datetime.now()) )
    client.publish("home/in","1")
    client.publish("home/in","-1")
    ## if asked
    ##client.publish("home/in","T_UP")
    ##client.publish("home/in","H_UP")
    if "T " in str(message.payload.decode('utf-8')):
        with open('temperatura.txt','a+') as f:
         f.write( str(message.payload.decode('utf-8')) + " " + str(datetime.now()) +  "\n")
    if "H " in str(message.payload.decode('utf-8')):
        with open('humidade.txt','a+') as f:
         f.write( str(message.payload.decode('utf-8')) + " " + str(datetime.now()) +  "\n")
    if "T_UP " in str(message.payload.decode('utf-8')):
        with open('temperatura_up.txt','w') as f:
         f.write( str(message.payload.decode('utf-8')) + " " + str(datetime.now()) +  "\n")
    if "H_UP " in str(message.payload.decode('utf-8')):
        with open('humidade_up.txt','w') as f:
         f.write( str(message.payload.decode('utf-8')) + " " + str(datetime.now()) +  "\n")

    

Connected = False   #global variable for the state of the connection

broker_address= "192.168.1.98"  #Broker address
port = 1883                         #Broker port
#user = "me"                    #Connection username
#password = "abcdef"            #Connection password

client = mqttClient.Client("Python")               #create new instance
#client.username_pw_set(user, password=password)    #set username and password
client.on_connect= on_connect                      #attach function to callback
client.on_message= on_message                      #attach function to callback
client.connect(broker_address,port,60) #connect
client.subscribe("home/out_t") #subscribe
client.subscribe("home/out_h") #subscribe
client.publish("home/in","-1")
client.loop_forever() #then keep listening forever
