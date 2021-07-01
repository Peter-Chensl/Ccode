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

namespace 网上鲜果系统
{
    public partial class 购买界面 : Form
    {
        public 购买界面()
        {
            InitializeComponent();
        }
        public void Database_Select_All()
        {

            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=shuiguo";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                Console.WriteLine("查询");
                string sql_select = "select * from xianguo";
                MySqlCommand cmd = new MySqlCommand(sql_select, sq);
                //将查询结果绑定dataview源
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "xianguo");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "xianguo";
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                sq.Close();
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            string comm = "server = localhost;port=3306;user=root;password=123456;database=shuiguo";
            MySqlConnection sq = new MySqlConnection(comm);
            try
            {
                string sql = string.Format("select count from xianguo where sid='{0}'and count != 0 ", this.dataGridView1.CurrentCell.Value);//拼写sql语句删除用户
                sq.Open();
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                MySqlDataReader reader = cmd.ExecuteReader();

                if (reader.Read())
                {
                    int count = reader.GetInt32(reader.GetOrdinal("count"));
                    if (count > 0)
                    {
                        reader.Close();
                        string sql1 = string.Format("update xianguo set count = count -1 where sid = '{0}'", this.dataGridView1.CurrentCell.Value);
                        MySqlCommand cmd1 = new MySqlCommand(sql1, sq);

                        int y = cmd1.ExecuteNonQuery();
                        count--;
                        if (y != 0)
                        {
                            MessageBox.Show("购买成功！");

                        }
                        else
                        {

                            MessageBox.Show("购买失败！");
                        }
                    }
                    if (count == 0)
                    {
                            MessageBox.Show("库存不足！");
                    }
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
                Application.Exit();
            }
            finally
            {
                sq.Close();
                sq.Dispose();

            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=shuiguo";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                string sql = string.Format("select * from xianguo where sname like '%{0}%'", textBox2.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "xianguo");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "xianguo";
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

        private void 购买界面_Load(object sender, EventArgs e)
        {
            Database_Select_All(); 
        }
    }
}
