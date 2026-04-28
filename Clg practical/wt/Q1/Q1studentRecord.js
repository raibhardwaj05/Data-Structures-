const { MongoClient } = require('mongodb');

const client = new MongoClient('mongodb://localhost:27017');
const dbName = 'CollegeDB';

async function run() {
    await client.connect();
    const col = client.db(dbName).collection('students');

    // INSERT
    await col.insertMany([
        { name: "John", rollNo: 101, course: "CE" },
        { name: "Jane", rollNo: 102, course: "IT" }
    ]);

    // READ
    console.log(await col.find().toArray());

    // UPDATE
    await col.updateOne({ rollNo: 101 }, { $set: { course: "DS" } });

    // QUERY
    console.log(await col.find({ course: "IT" }).toArray());

    // DELETE
    await col.deleteOne({ rollNo: 102 });

    await client.close();
}

run();