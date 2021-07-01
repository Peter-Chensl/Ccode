using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace 学生成绩管理系统
{
    public partial class 成绩查询 : Form
    {
        private String SQL_ConnectStr = "server = localhost;port=3306;user=root;password=123456;database=score";
        public MySqlConnection MySqlConnection;

        MySqlDataAdapter mySqlDataAdpter;
        DataSet ds;
        public 成绩查询()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)//刷新按钮点击事件
        {
            ds.Tables["scores"].Clear();
            mySqlDataAdpter.Fill(ds, "scores");
        }
        public void Database_connection()
        {
            try
            {
                MySqlConnection = new MySqlConnection(SQL_ConnectStr);
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                Console.WriteLine("数据库连接成功");
            }
        }
        public void Database_Select_All(MySqlConnection mySqlConnection)
        {
            try
            {
                if (mySqlConnection != null)
                    mySqlConnection.Open();
                Console.WriteLine("查询");
                string sql_select = "select * from scores";
                MySqlCommand cmd = new MySqlCommand(sql_select, mySqlConnection);
                //将查询结果绑定dataview源
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "scores");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "scores";
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                mySqlConnection.Close();
            }
        }
        private void button5_Click(object sender, EventArgs e)
        {
            System.Environment.Exit(0);
        }

        private void 成绩查询_Load(object sender, EventArgs e)
        {

            Database_connection();
            Database_Select_All(MySqlConnection);

        }

        private void button4_Click(object sender, EventArgs e)
        {
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=score";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                string sql = string.Format("select * from books where object= '{0}'", textBox1.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "scores");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "scores";
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            finally
            {
                sq.Close();
            }
        }
    }
}
