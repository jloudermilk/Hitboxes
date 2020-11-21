using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;


public class NativeScript : MonoBehaviour
{

    [StructLayout(LayoutKind.Sequential)]
    public struct Box
    {
        public Vector3 pos;
        public Vector2 size;
        //public vector<string> tags;
        public int boxId;
        public Vector4 color;
        public bool iFrame;

    };
    

    [DllImport("Hitboxes", EntryPoint = "CreateBox")]
    public static extern int CreateBox(Box box);
    [DllImport("Hitboxes", EntryPoint = "GetBox")]
    public static extern Box GetBox(int boxId);

    List<Box> boxes = new List<Box>();
    Mesh mesh;
    public Material mat;
    Matrix4x4 matrix;
    // Start is called before the first frame update
    void Start()
    {

        SetupQuad();
        Box b1 = new Box();
        b1.pos = Vector3.down;
        b1.size = new Vector2(1, 1);
        b1.color = new Vector4(1, 0, 0, .5f);
        b1.boxId = CreateBox(b1);
        boxes.Add(b1);

        b1 = new Box();
        b1.pos = Vector3.up;
        b1.size = new Vector2(1, 1);
        b1.color = new Vector4(0, 1, 0, .5f);
        b1.boxId = CreateBox(b1);
        boxes.Add(b1);

        b1 = new Box();
        b1.pos = Vector3.left;
        b1.size = new Vector2(1, 1);
        b1.color = new Vector4(0, 0, 1, .5f);
        b1.boxId = CreateBox(b1);
        boxes.Add(b1);

        b1 = new Box();
        b1.pos = Vector3.right;
        b1.size = new Vector2(1, 1);
        b1.color = new Vector4(1, 0, 0, .5f);
        b1.boxId = CreateBox(b1);
        boxes.Add(b1);


        matrix = Matrix4x4.identity;
    }
    void SetupQuad()
    {
        mesh = new Mesh();
        Vector3[] vertices = new Vector3[4]
         {
             new Vector3(-0.5f, 0.5f, 0.0f),
             new Vector3(0.5f, 0.5f, 0.0f),
             new Vector3(-0.5f, -0.5f, 0.0f),
             new Vector3(0.5f, -0.5f, 0.0f)
         };
        mesh.vertices = vertices;

        int[] tris = new int[6]
        {
            // lower left triangle
            0, 2, 1,
            // upper right triangle
            2, 3, 1
        };
        mesh.triangles = tris;
        Vector3[] normals = new Vector3[4]
        {
            -Vector3.forward,
            -Vector3.forward,
            -Vector3.forward,
            -Vector3.forward
        };
        mesh.normals = normals;
        Vector2[] uv = new Vector2[4]
        {
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(0, 1),
            new Vector2(1, 1)
        };
        mesh.uv = uv;
    }
    // Update is called once per frame
    void Update()
    {

        foreach (Box b in boxes)
        {
            RenderBox(b);
        }
    }

    void RenderBox(Box box)
    {
        //change matrix based on box
        matrix[0, 0] = box.size.x;
        matrix[0, 3] = box.pos.x;
        matrix[1, 1] = box.size.y;
        matrix[1, 3] = box.pos.y;
        matrix[2, 3] = box.pos.z;
        // colors arnt working so next thing to fix
        mat.color = box.color;

        Graphics.DrawMesh(mesh, matrix, mat, 0);
    }

    private void LateUpdate()
    {


    }

}