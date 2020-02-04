import json
import ijson

print("Here: Start")

data1 = [
    {
        "'Temperature'": 4,
        "'Output Current'": 0,
        "'Motor Output Percent'": -0.399804,
        "'Motor Output Voltage'": -3.01852,
        "'Sensor Position'": 3342,
        "'Sensor Velocity'": 0,
        "'ActiveTrajectoryArbFeedFwd'": 0,
        "'GetActiveTrajectoryPosition'": 0,
        "'ActiveTrajectoryVelocity'": 0,
        "'Bus Voltage'": 7.55
    },
    {
        "'Temperature'": 4,
        "'Output Current'": 0,
        "'Motor Output Percent'": -0.399804,
        "'Motor Output Voltage'": -3.01852,
        "'Sensor Position'": 3342,
        "'Sensor Velocity'": 0,
        "'ActiveTrajectoryArbFeedFwd'": 0,
        "'GetActiveTrajectoryPosition'": 0,
        "'ActiveTrajectoryVelocity'": 0,
        "'Bus Voltage'": 7.55
    }
]

with open("data_file_out.json", "w") as write_file:
    json.dump(data1, write_file)
print("Here: File write complete")

# Parse the input file a build payload for API
myPayload = ""
with open("testData.json", "r") as read_file:
    parser = ijson.parse(read_file)
    for prefix, event, value in parser:
        if prefix == "Samples.item.motor.Temperature":
            print("{'Temperature': ", value, ",")
            myPayload = "{'Temperature':" + str(value) + ","
        if prefix == "Samples.item.motor.Output Current":
            print("'Output Current': ", value, ",")
            myPayload = myPayload + "'Output Current':" + str(value) + ","
        if prefix == "Samples.item.motor.Motor Output Percent":
            print("'Motor Output Percent': ", value, ",")
            myPayload = myPayload + "'Motor Output Percent':" + str(value) + ","
        if prefix == "Samples.item.motor.Motor Output Voltage":
            print("'Motor Output Voltage': ", value, ",")
            myPayload = myPayload + "'Motor Output Voltage':" + str(value) + ","
        if prefix == "Samples.item.motor.Sensor Position":
            print("'Sensor Position': ", value, ",")
            myPayload = myPayload + "'Sensor Position':" + str(value) + ","
        if prefix == "Samples.item.motor.Sensor Velocity":
            print("'Sensor Velocity': ", value, ",")
            myPayload = myPayload + "'Sensor Velocity':" + str(value) + ","
        if prefix == "Samples.item.motor.ActiveTrajectoryArbFeedFwd":
            print("'ActiveTrajectoryArbFeedFwd': ", value, ",")
            myPayload = myPayload + "'ActiveTrajectoryArbFeedFwd':" + str(value) + ","
        if prefix == "Samples.item.motor.GetActiveTrajectoryPosition":
            print("'GetActiveTrajectoryPosition': ", value, ",")
            myPayload = myPayload + "'GetActiveTrajectoryPosition':" + str(value) + ","
        if prefix == "Samples.item.motor.ActiveTrajectoryVelocity":
            print("'ActiveTrajectoryVelocity': ", value, ",")
            myPayload = myPayload + "'ActiveTrajectoryVelocity':" + str(value) + ","
        if prefix == "Samples.item.motor.Bus Voltage":
            print("'Bus Voltage': ", value, "}")
            myPayload = myPayload + "'Bus Voltage':" + str(value) + "}"
        if prefix == "Samples.item.motor.PID":
            print("***** Make call to Thingworx for PID ", value, " *****")
            print(myPayload)



print("Here: End ")
