const { MongoClient } = require('mongodb');

const client = new MongoClient('mongodb://localhost:27017');

async function run() {
    await client.connect();
    const col = client.db('CollegeRecordsDB').collection('students');

    await col.insertMany([
        { name: "Amit", rollNo: "CS201", course: "CE" },
        { name: "Priya", rollNo: "CS202", course: "IT" }
    ]);

    console.log(await col.find().toArray());

    await col.updateOne({ rollNo: "CS202" }, { $set: { course: "DS" } });

    await col.deleteOne({ rollNo: "CS201" });

    await client.close();
}

run();